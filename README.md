#Project in collaboration by Santiago Herrera and Carlos Zuluaga, intended to learn how printf works#

This project contains several brand new files with C code, which contain the functions needed to print as well as the standard printf function does.

The main function must be created by the user, and the header holberton.h must be included as a preprocessor directive. (#include "holberton.h" in the main function of the user"

holberton.h contains all functions prototypes used in the project.

Main features and format directives implemented:
%s: prints a string
%c: prints a char
%u: prints an unsigned int
%d, %i: prints an integer
%r: prints a string in reverse order
%b: converts an unsigned int to binary
%x, %X: convert an unsigned int to hexadecimal
special characters handling: \n, \t, \a, \f among others
buffer: the function performs only one system call (write())
