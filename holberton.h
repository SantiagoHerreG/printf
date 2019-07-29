#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>

int _special_chars(char *str);
int _write_char(char c);
int _print_string(char *s);
int _print_number(int n, int count);
int _printf(const char *format, ...);
int _print_selector(char *, va_list);
int _print_percentage(char *str);
int _print_str(char *str);
int _print_binary(unsigned int n, int count);
int _print_octal(unsigned int n, int count);

#endif /* HOLBERTON H */
