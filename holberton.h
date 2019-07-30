#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>

int _special_chars(char *str, char *buffer);
int _write_char(char c, char *buffer);
void _print_string(char *s, int count);
int _print_number(int n, int count, char *buffer);
int _printf(const char *format, ...);
int _print_selector(char *, va_list, char *buffer);
int _print_percentage(char *str, char *buffer);
int _print_str(char *str, char *buffer);
int _print_binary(unsigned int n, int count, char *buffer);
int _print_octal(unsigned int n, int count, char *buffer);
int _string_to_buff(char *str, char *buffer);

#endif /* HOLBERTON H */
