
# ft_printf

This project aims to recreate the printf function from the standard library.
The primary objective is to learn how to use variadic functions, parsing and handling flags and specifiers, and how to handle different types of data.

### Supported conversions - Mandatory

- `%c` print a character
- `%s` print a string
- `%d` and %i print a decimal number
- `%u` print an unsigned decimal number
- `%x` and %X print a hexadecimal number
- `%p` print a pointer address
- `%%` print a percent symbol

### Examples of Use

Compile with the main.c in subject folder.

## Instructions
Run the command `make` to compile the `libftprintf.a` library.
After the compilation is complete, you can use the libftprintf.a library in your projects.

To clean the object files generated during compilation, run the command `make clean`.
To remove the libftprintf.a library, run the command `make fclean`.
To recompile the entire project, run the command `make re`.

## Grade: 100 / 100

## Used Tests
- Francinette: https://github.com/xicodomingues/francinette

### Disclaimer

Maybe you could notice a different coding style. At 42 we need to follow some rules according to the coding standard of the school such as:
```
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
Click here to read the norm file of 42 school.
