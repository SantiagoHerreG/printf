#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>

int _special_chars(int *p, char *str, char *buffer, int count);
int _write_char(int *p, char c, char *buffer, int count);
void _print_string(char *s, int count);
int _print_number(int *p, int n, int count, char *buffer);
int _printf(const char *format, ...);
int _print_selector(char *, va_list, char *buffer);
int _print_percentage(int *p, char *str, char *buffer, int count);
int _print_str(int *p, char *str, char *buffer, int count);
int _print_binary(int *p, unsigned int n, int count, char *buffer);
int _print_octal(int *p, unsigned int n, int count, char *buffer);
int _string_to_buff(int *p, char *str, char *buffer, int count);
int _print_h(int *p, char option, unsigned int n, char *buffer, int count);
int _print_unsigned_int(int *p, unsigned int n, int count, char *buffer);
int _print_rev(int *p, char *str, char *buffer, int count);
int _print_rot13(int *p, char *str, char *buffer, int count);
int _print_ptr(int *p, unsigned long n, char *buffer, int count);


#endif /* HOLBERTON H */
