# Calculator

A simple calculator written in C that supports basic arithmetic operations, parentheses, decimal numbers, and negative numbers.

## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`x`), and division (`/`).
- Handles parentheses for operation precedence.
- Supports decimal numbers and negative numbers.

## Compilation

```bash
make re
```

## Usage

Run the calculator with an expression as an argument:

```bash
./calculator "expression"
```

### Examples

```bash
./calculator "3.2+5"
Result = 8.200000
```

```bash
./calculator "5x(8-3)"
Result = 25.000000
```

```bash
./calculator "-5x(8-3)"
Result = -25.000000
```

## Available Commands

### Build Commands

- `make all` or `make`: Compile the project.
- `make re`: Clean and rebuild everything.
- `make clean`: Remove object files and temporary files.
- `make fclean`: Remove compiled binaries and clean files.
- `make debug`: Compile with debugging flags (`-ggdb3`).

### Source Files

The project is structured as follows:

```
📂 src
├── 📄 main.c
├── 📄 operation.c
├── 📄 parentheses.c
│
├── 📂 expression
│   ├── 📄 evaluator.c
│   ├── 📄 parser.c
│   ├── 📄 part.c
│
├── 📂 utils
│   ├── 📄 list.c
│   ├── 📄 delete_char.c
│   ├── 📄 is_digit.c
│   ├── 📄 strtod.c
```

## Compilation Flags

- `CFLAGS`: `-W -Wall -Wextra -O1` (Enables warnings for better code quality).
- `CPPFLAGS`: `-I./include` (Includes the header files from the `include/` directory).

## Author
- [Kévin Demy](https://github.com/Sakutaroo)
