*This project has been created as part of the 42 curriculum by sait-mou.*

## Description

The ft_printf project is a comprehensive re-implementation of the standard C library function printf(3). The primary goal is to understand the mechanics of variadic functions and gain mastery over low-level system interactions, specifically the use of the write system call.
Goal and Overview

This function takes a format string and a variable number of arguments, converts the arguments according to the specified format, and writes the resulting string to the standard output (file descriptor 1). The challenge lies in accurately processing the format specifiers and correctly extracting arguments of differing types from the memory stack.
Conversions Implemented

The mandatory part implements the following format specifiers:
Specifier	Description
%c	Prints a single character.
%s	Prints a string.
%p	Prints the argument void * pointer in hexadecimal format.
%d	Prints a signed decimal integer.
%i	Prints a signed integer (identical to %d).
%u	Prints an unsigned decimal integer.
%x	Prints a number in hexadecimal (base 16) lowercase.
%X	Prints a number in hexadecimal (base 16) uppercase.
%%	Prints a percent sign.
Instructions
Compilation

The project uses a standard Makefile to compile the source files (ft_printf.c, ft_puts.c) into a static library.

    Clone the repository

Build the static library:
    make

Installation and Execution

To use ft_printf in your own program (e.g., a test file named main.c):

    Include the header #include "ft_printf.h"

Compile and link your code with the library:
Bash

    cc main.c libftprintf.a -o my_test
    ./my_test

    (Note: The custom libftprintf.a must be placed after your source file in the compilation command for the linker to resolve symbols correctly.)

Technical Choices and Implementation Details
Chosen Algorithm: Format String Dispatch

The algorithm follows a Parse-Dispatch-Convert pattern:

    Main Loop (ft_printf): The function iterates through the format string character by character.

    Parse: If a character is not '%', it is printed directly using write(1, ...) and the count is incremented.

    Dispatch: If a '%' is encountered, the iterator is advanced to the next character (the specifier), and control is passed to a helper function (format_checker).

    Convert: The format_checker identifies the conversion type (c, s, d, p, etc.) and calls the appropriate utility function (put_char, put_str, put_number, etc.), passing the current position of the argument list (va_list).

Data Structure: va_list and Recursion
Variadic List (va_list)

The central data structure is the C standard macro va_list (from <stdarg.h>).

    Role: va_list acts as a cursor, specifically tracking the location of the next argument on the CPU's registers or the system stack.

    Access: The list is initialized using va_start and advanced using va_arg(list, type). The correct type must be provided to ensure the correct number of bytes (4 bytes for int, 8 bytes for void *, etc.) is read and the cursor is advanced accurately.

Number Conversion (Recursion)

All numeric conversion functions (%d, %u, %x, etc.) utilize a recursive algorithm.

    Justification: When converting a number (e.g., 42) to a string, the least significant digit (2) is found first via the modulo operator (n % base). However, the most significant digit (4) must be printed first. Using recursion allows the function to build the string in reverse order on the call stack, ensuring the digits are printed in the correct human-readable sequence when the stack unwinds.

Pointer Printing Justification (%p)

    Casting: The void * pointer is cast to an unsigned long long. This is critical on modern 64-bit systems because pointers are 8 bytes (64 bits). Using long long guarantees the full address is captured without truncation, and unsigned ensures it is treated as a non-negative memory address.

    Format: The pointer value is then converted to hexadecimal (base 16) and manually prefixed with "0x" to adhere to the standard format.

## Resources

This project heavily relies on understanding the C standard library and memory layout.

    Standard Variadic Functions (The Bible):

        C++ Reference: Variadic arguments (stdarg.h)

    System Calls:

        man page for write(2)

    Printf Specification:

        C standard printf reference

AI Usage

AI assistance (specifically Google's Gemini) was used for the following tasks:

    Conceptual Explanation: Deep dives and theoretical review of variadic function memory handling (stack vs. registers) and the necessity of casting pointers to unsigned long long.