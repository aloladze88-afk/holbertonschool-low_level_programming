# Simple Calculator (C)

A small menu-based calculator that runs in the terminal.

## Compile
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run
./calculator

## Features
- Add, Subtract, Multiply, Divide
- Menu runs in a loop until you choose 0 (Quit)
- Prints "Invalid choice" for options outside 0–4
- Prints "Error: division by zero" if you try to divide by 0

## Numeric behaviour
Uses integers (int).

## Limitations
Basic input handling only (assumes the user types integers when asked).