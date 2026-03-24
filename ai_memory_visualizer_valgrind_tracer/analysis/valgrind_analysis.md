# valgrind_analysis.md

## Purpose

This file explains what Valgrind Memcheck should be telling you **and why**.

The goal is not to paste diagnostics. The goal is to connect each warning to:

- the exact memory object involved
- the lifetime rule that was broken
- the code that caused the misuse

---

## Commands to run

Typical commands for this project:

```bash
cd programs
make
valgrind --leak-check=full --show-leak-kinds=all ./heap_example
valgrind --leak-check=full --show-leak-kinds=all ./aliasing_example
```

Optional for uninitialised-value investigations:

```bash
valgrind --track-origins=yes ./program_name
```

---

## Program 1: `heap_example`

### Expected issue type

**Memory leak**  
More precisely: **definitely lost memory** caused by **lost ownership** of Alice's `name` block.

### Memory object involved

The leaked object is the heap-allocated string for Alice:

```c
p->name = (char *)malloc(len + 1);
```

For `"Alice"`, that block is 6 bytes long (`'A' 'l' 'i' 'c' 'e' '\0'`).

### Why the leak happens

The program correctly frees Bob:

```c
free(bob->name);
free(bob);
```

But for Alice it does:

```c
person_free_partial(alice);
```

and that function only frees the struct:

```c
free(p);
```

So the program releases the `Person` block but forgets the separate heap block stored in `p->name`.

After the struct is freed, the pointer to Alice's name is lost. The string block still exists, but no valid pointer to it remains. That is why the leak is a **lost ownership** problem.

### Correct classification

- **Not** a stack issue
- **Not** use-after-free
- **Yes**: heap leak
- **Yes**: definitely lost block, because the last usable pointer to the name block was lost

### AI mistake I corrected

**Incorrect AI-style claim:**  
“Both the Alice struct and Alice name are leaked.”

**Why that is incomplete/wrong:**  
The Alice struct itself is **not** leaked, because `free(p)` is called. Only the nested `name` allocation is leaked.

---

## Program 2: `aliasing_example`

### Expected issue type

This program should produce **use-after-free** errors.

Typical categories:

- **Invalid read**
- **Invalid write**

### Memory object involved

The affected object is the heap array allocated in `make_numbers(n)`:

```c
arr = (int *)malloc((size_t)n * sizeof(int));
```

In this run, the array has 5 integers.

### Why the issue happens

This is the key sequence:

```c
a = make_numbers(n);
b = a;
free(a);
```

At that point:

- `a` and `b` still hold the old address value
- but the array has already been freed

So `b` is a dangling pointer.

The later operations:

```c
b[2]
b[3] = 1234
b[3]
```

all treat freed memory as if it were still a live array.

### Correct classification by line of reasoning

#### 1. `printf("  reading b[2]=%d\n", b[2]);`

- **Type:** invalid read
- **Why:** `b` points to a block whose lifetime ended at `free(a)`

#### 2. `b[3] = 1234;`

- **Type:** invalid write
- **Why:** the program writes into memory that has already been freed

#### 3. `printf("  wrote b[3]=%d\n", b[3]);`

- **Type:** another invalid read
- **Why:** reading from the same freed block again

### Important nuance

This line:

```c
printf("  after free(a): b=%p (dangling)\n", (void *)b);
```

prints the pointer value only. It does **not** dereference the freed block.

So the important misuse is not “using the variable `b` at all”.  
The misuse is **dereferencing `b` after the array has been freed**.

### Correct terminology

The best labels here are:

- **aliasing**
- **dangling pointer**
- **use-after-free**
- **invalid read**
- **invalid write**

### AI mistake I corrected

**Incorrect AI-style claim:**  
“Printing `b` after `free(a)` is itself the same kind of invalid read as `b[2]`.”

**Why that is misleading:**  
Printing the raw pointer value does not read the freed array. `b[2]` does. The stale pointer value is dangerous because it can still be dereferenced, not because the variable stops existing.

---

## Program 3: `stack_example`

### Expected issue type

No memory misuse is expected here during normal execution.

### Why

The recursive frames are valid while active, and the program does not:

- free heap memory incorrectly
- read uninitialised data
- dereference invalid pointers
- write out of bounds

This program is mainly for **mental model building**, not for Valgrind errors.

### What Valgrind would reinforce

Valgrind should not report a bug just because stack frames appear and disappear.  
Function return is normal lifetime completion for stack objects.

---

## Uninitialised-memory category

The task asks us to capture uses of uninitialised memory if they exist.

For these provided programs:

- `heap_example` → no clear uninitialised-value use is expected
- `aliasing_example` → the main issue is use-after-free, not uninitialised memory
- `stack_example` → no clear uninitialised-value use is expected

So the important findings in this bundle are:

1. **leak due to lost ownership**
2. **invalid read after free**
3. **invalid write after free**

---

## Final summary

### `heap_example`
- **Valgrind category:** leak
- **Root cause:** forgot to free `alice->name`
- **Precise explanation:** struct freed, nested string block left allocated and unreachable

### `aliasing_example`
- **Valgrind categories:** invalid read / invalid write
- **Root cause:** `b` aliases `a`; `free(a)` ends the array lifetime for both names
- **Precise explanation:** later dereferences of `b` are use-after-free

### `stack_example`
- **Valgrind category:** expected clean run
- **Root cause:** none
- **Precise explanation:** stack lifetimes end normally on function return

---

## One-sentence rule to remember

Valgrind is useful only if you can translate its warning into plain English:

> “This specific object stopped being valid here, but the program still tried to use it there.”
