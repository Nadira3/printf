#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#define BUFSIZE 1024

/**
 * struct format - a template for the format specifiers and corresponding
 * function pointers
 * @f: format specifier
 * @func: function pointer
 */
typedef struct format
{
	char *f;
	size_t (*func)(va_list);
} specifier;

size_t printchar(va_list list);
size_t printstring(va_list list);
char *buf_init(char *);
int _printf(const char *, ...);
int _putchar(char);

#endif
