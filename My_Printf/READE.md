# Welcome to My Printf
The very first thing we do when learning a programming language is to write "Hello World !" on the screen , and this is what i will be doing in this exercise
i will writing custom code for the printf function and this code will reproduce thesame output that the printf function output.
This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.
I will strengthen my programming skills and learn new programming concepts: variadic functions and variable argument lists.
Recoding printf is also a good exercise to learn to have.
## Task
The task at hand is to implement a custom version of the printf function in C.
This involves understanding the functionality and behavior of printf, including handling various format specifiers and formatting options.
Additionally, the challenge lies in ensuring the code is well-structured, modular, and adheres to strict requirements.
requiremnts such as memory management and error handling.


## Description
In this project, I have implemented the my_printf() function, which mimics the behavior of the standard printf function in C.
The function takes a format string along with optional arguments and produces output accordingly.
It supports various format specifiers such as %d, %u, %o, %x, %c, %s, and %p, handling different data types and converting them to their respective string representations.
I've utilized concepts such as variadic functions and variable argument lists (stdarg.h) to achieve this functionality.
Moreover, the code is designed to be modular and well-organized, making it easy to extend and maintain.

## Installation
To install this project, follow these steps:
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the code using the provided Makefile with the command `make`.
4. After compilation, you will find the executable `my_project` in the directory.
Or download as a zip file too your local machine.

## Usage
To use the my_printf function, follow these steps:
1. Include the header file `my_printf.h` in your C program.
2. Call the function `my_printf` with the desired format string and arguments.
3. Compile your program along with the `my_printf.c` file using the command `gcc -o my_program my_program.c my_printf.c`.
4. Execute the compiled program.

### The Core Team