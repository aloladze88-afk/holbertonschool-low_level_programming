# Holberton School - Low Level Programming

A collection of C programming projects focused on low-level concepts, memory management, pointers, data structures, algorithms, debugging, and secure coding.

![C](https://img.shields.io/badge/C-Programming-blue)
![Shell](https://img.shields.io/badge/Shell-Scripting-lightgrey)
![Status](https://img.shields.io/badge/Status-In%20Progress-brightgreen)
![School](https://img.shields.io/badge/Holberton-School-red)

## Description

This repository contains low-level programming projects completed as part of my software development training at Holberton School.

The main goal of this repository is to build a solid understanding of how programmes work closer to the machine level. The projects cover C syntax, compilation, memory management, pointers, arrays, strings, recursion, linked lists, hash tables, file handling, debugging, dynamic analysis, and secure data handling.

These projects helped me understand not only how to write code, but also how memory, data structures, and programme execution work underneath higher-level languages.

## Projects

| Directory | Description |
|---|---|
| `hello_world` | Introduction to C, compilation, basic output, and the C development workflow. |
| `variables_if_else_while` | Variables, conditional statements, loops, and basic control flow. |
| `functions_nested_loops` | Functions, nested loops, prototypes, and basic programme structure. |
| `more_functions_nested_loops` | Additional practice with functions, loops, and logical problem solving. |
| `pointers_arrays_strings` | Pointers, arrays, strings, memory addresses, and character manipulation. |
| `recursion` | Recursive functions and solving problems by breaking them into smaller repeated steps. |
| `argc_argv` | Command-line arguments in C using `argc` and `argv`. |
| `malloc_free` | Dynamic memory allocation using `malloc` and memory release using `free`. |
| `more_malloc_free` | More advanced dynamic memory allocation exercises. |
| `structures_typedef` | Structures, custom data types, and `typedef`. |
| `function_pointers` | Function pointers and passing behaviour as data. |
| `variadic_functions` | Functions that accept a variable number of arguments. |
| `singly_linked_lists` | Building and manipulating singly linked lists. |
| `doubly_linked_lists` | Building and manipulating doubly linked lists. |
| `hash_tables` | Hash functions, hash tables, collisions, and key-value storage. |
| `file_io` | Reading from and writing to files using system calls. |
| `intro_debugging` | Introduction to debugging and identifying programme errors. |
| `dynamic_analysis` | Runtime analysis and memory checking. |
| `benchmarking` | Measuring and comparing programme performance. |
| `secure_data_handling` | Safer handling of data and memory in C programmes. |
| `simple-calculator` | Small practical C project applying functions and programme structure. |
| `ai_memory_visualizer_valgrind_tracer` | Memory visualisation and analysis using Valgrind-related concepts. |

## Learning Objectives

By working on this repository, I practised how to:

- Write, compile, and run C programmes
- Use variables, loops, conditionals, and functions
- Understand pointers and memory addresses
- Manipulate arrays and strings manually
- Allocate and free memory dynamically
- Use structures and custom data types
- Work with function pointers and variadic functions
- Build linked lists and hash tables
- Read from and write to files
- Debug C programmes
- Analyse memory usage and performance
- Follow strict C coding standards
- Write clearer, safer, and more maintainable low-level code

## Technologies Used

- C
- Shell
- GCC
- Betty style checker
- Valgrind
- Git
- GitHub
- Linux / Ubuntu

## Requirements

To work with this repository, you may need:

- Ubuntu 20.04 or later
- GCC compiler
- Betty style checker
- Valgrind
- Git
- A code editor such as VS Code, Vim, or Emacs

Most files are compiled with flags similar to:

```bash
gcc -Wall -Werror -Wextra -pedantic file.c -o program
```

Some projects may have their own specific compilation requirements inside their project folders.

## Installation

Clone the repository:

```bash
git clone https://github.com/aloladze88-afk/holbertonschool-low_level_programming.git
```

Move into the repository:

```bash
cd holbertonschool-low_level_programming
```

Move into the project you want to inspect or run:

```bash
cd hello_world
```

or:

```bash
cd singly_linked_lists
```

## Usage

Example of compiling a C file:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-file.c -o program
```

Run the compiled programme:

```bash
./program
```

Example with Valgrind for memory checking:

```bash
valgrind ./program
```

Example of checking code style with Betty:

```bash
betty file.c
```

Always check the README inside each project folder for the exact compilation and usage instructions required by that specific task.

## Features

- C programming exercises
- Manual memory management
- Pointer and string manipulation
- Recursive functions
- Static and dynamic libraries
- Command-line argument handling
- Structures and typedef
- Function pointers
- Variadic functions
- Singly and doubly linked lists
- Hash tables
- File input/output
- Debugging practice
- Dynamic memory analysis
- Benchmarking and performance awareness
- Secure data handling practice

## Repository Structure

```text
holbertonschool-low_level_programming/
├── ai_memory_visualizer_valgrind_tracer/
├── argc_argv/
├── benchmarking/
├── doubly_linked_lists/
├── dynamic_analysis/
├── file_io/
├── function_pointers/
├── functions_nested_loops/
├── hash_tables/
├── hello_world/
├── intro_debugging/
├── malloc_free/
├── more_functions_nested_loops/
├── more_malloc_free/
├── pointers_arrays_strings/
├── recursion/
├── secure_data_handling/
├── simple-calculator/
├── singly_linked_lists/
├── structures_typedef/
├── variables_if_else_while/
├── variadic_functions/
├── .gitignore
└── README.md
```

## Code Style

This repository follows Holberton School low-level programming standards.

The main standards used are:

- Betty style for C code
- Clean indentation and formatting
- Clear function prototypes
- Meaningful variable and function names
- No unnecessary global variables
- Careful memory allocation and memory release
- Header files used where appropriate
- Compilation with strict warning flags

## Documentation Standard

C functions are documented using Holberton-style function comments.

Example:

```c
/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}
```

Each function comment should explain:

| Part | Purpose |
|---|---|
| Function name | What the function does |
| Parameters | What each argument represents |
| Return value | What the function returns |
| Side effects | Any memory allocation, printing, or file operation if relevant |

## Branching Strategy

The stable branch is:

```text
main
```

A professional workflow may also include:

```text
development
tests
```

Recommended branch roles:

| Branch | Purpose |
|---|---|
| `main` | Stable and reviewed work |
| `development` | New improvements and code updates |
| `tests` | Testing, validation, debugging, and experiments |

## Screenshots

Most projects in this repository are terminal-based C exercises, so screenshots are not always applicable.

For projects involving memory visualisation, debugging, benchmarking, or command-line output, screenshots can be added later to show programme execution, Valgrind output, or performance results.

## Author

Aleksandre Loladze  
Software development student at Holberton School  
Thonon-les-Bains, France  

Email: aloladze88@gmail.com

## Acknowledgements

This repository was completed as part of the Holberton School software development curriculum.
