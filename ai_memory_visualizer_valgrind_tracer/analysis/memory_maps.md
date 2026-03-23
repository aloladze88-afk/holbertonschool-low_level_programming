# Memory Maps

## stack_example.c

This program shows how the stack works during recursion.

At each function call, a new stack frame is created.  
Each frame has its own local variables, even if the variable names are the same.

### Stack
- `depth`
- `local_int`
- `p_local`
- `local_buf`
- `marker`

### Heap
- none

### Lifetime
The local variables exist only while that function call is active.  
When the function returns, that stack frame is destroyed.

### Important point
`p_local` points to `local_int` in the same stack frame.  
At each recursive depth, the printed addresses change, which shows that each call has its own separate local variables.

---

## aliasing_example.c

This program shows pointer aliasing and a dangling pointer.

### Before free(a)

#### Stack
- pointer `a`
- pointer `b`

#### Heap
- one allocated block

Both `a` and `b` point to the same heap block.  
That means they are aliases.

### After free(a)

#### Stack
- `a` still exists as a variable
- `b` still exists as a variable

#### Heap
- the allocated block has been freed

After `free(a)`, `b` still holds the old address, but that memory is no longer valid.  
So `b` becomes a dangling pointer.

### Lifetime
The heap block exists from `malloc` until `free`.  
After `free`, the object’s lifetime is over.

### Important point
If two pointers point to the same heap block, freeing it through one pointer makes the other pointer invalid for use as well.

---

## AI mistake I corrected

A weak AI explanation would be:

> “After free(a), b points somewhere invalid.”

That is too vague.

My correction:
- `a` and `b` pointed to the same heap block
- `free(a)` freed that shared block
- `b` did not become a new valid pointer
- `b` became a dangling pointer
- reading or writing through `b` after that is invalid

---

## Conclusion

This task showed that:
- recursion creates separate stack frames
- local stack variables live only during their function call
- heap memory lives until it is freed
- two pointers can alias the same heap object
- freeing one shared heap object makes all aliases invalid for use
