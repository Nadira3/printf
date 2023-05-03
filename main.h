#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define BUFSIZE 2048

/**
 * struct format - a template for the format specifiers and corresponding
 * function pointers
 * @f: format specifier
 * @func: function pointer
 */
typedef struct format
{
	char *f;
	int (*func)(va_list, char);
} specifier;

int _putchar(char str);
int print_percent(va_list list, char);
int (*get_format(char ch))(va_list, char);
int buf_count(int len);
void _puts(char *s);
int print_int(va_list, char);
int u_print_int(va_list, char);
void split_num(long int n);
int printchar(va_list);
int printstring(va_list, char);
int print_string_upper(va_list list, char);
int _printf(const char *, ...);
void buf_flush(char *buf);
int print_binary(va_list, char);
int print_octal(va_list, char);
int print_address(va_list, char);
void negative_binary_div(unsigned int n);
void negative_octal_div(unsigned int n);
void negative_hex_div(unsigned int n, int flag);
void binary_div(unsigned int n);
void octal_div(unsigned int n);
void hex_div(unsigned long int n, int flag);
int print_hex_upper(va_list list, char);
int print_hex_lower(va_list list, char);
char letter(unsigned int n, int flag);
void _print_rev_recursion(char *s);
int print_rev(va_list list, char);
void find_rot(char *s);
int print_rot13(va_list list, char);
char flag_check(char ch);

#endif
