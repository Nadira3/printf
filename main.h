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
	void (*func)(va_list);
} specifier;

int _putchar(char str);
void (*get_format(char ch))(va_list);
int buf_count(int len);
void _puts(char *s);
void print_int(va_list);
void u_print_int(va_list);
void split_num(int n);
void printchar(va_list);
void printstring(va_list);
int _printf(const char *, ...);
void buf_flush(char *buf);
void print_binary(va_list list);
void print_octal(va_list list);
void negative_binary_div(int n);
void negative_octal_div(int n);
void binary_div(int n);
void octal_div(int n);

#endif
