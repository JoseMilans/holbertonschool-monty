# Monty Interpreter
C - Stacks, Queues - LIFO, FIFO

holbertonschool-monty GitHub repository contains the C files for a simple interpreter for Monty ByteCodes files.

## Table of Contents

1. [Description](#description)
2. [Files](#files)
3. [Usage](#usage)
4. [Authors](#authors)

## Description

Monty language is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Files

### monty.h

Header file containing all the function prototypes and struct definitions.

- `stack_t`: Structure for stack elements. It contains an integer `n` and pointers to the previous and next elements of the stack.

- `instruction_t`: Structure for instructions. It contains a string `opcode` and a function pointer `f` that takes a double pointer to the head of the stack, an unsigned int `line_number`, and a string `arg`.

- `global_t`: Structure for global variables. It contains a file pointer `file`, a string `line`, a string `opcode`, and a string `arg`.

### main.c

Contains the `main` function which is the entry point of the program.

- `main`: Opens a file containing monty byte codes and executes them.

### 0-push_pall.c

Contains the `push` and `pall` functions.

- `push`: Pushes an element onto the stack.

- `pall`: Prints all values on the stack, starting from the top.

### util.c

Contains utility functions for parsing and executing instructions.

- `parse_line`: Parses a line of monty byte code.

- `exe_inst`: Executes a monty instruction.

- `free_stack`: Frees a `stack_t` stack.

## Usage

- Compile the program:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

- The program works like this in interactive mode:

```bash
$ ./monty "file".m
```

## Authors

>* Jose Milans (6764@holbertonstudents.com)
>* Fabian Tellechea (fabianagtellechea@gmail.com)