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
	void (*func)(va_list);
} specifier;

int _putchar(char str);
void (*get_format(char ch))(va_list);
int buf_count(int len);
void printchar(va_list);
void printstring(va_list);
int _printf(const char *, ...);
void buf_flush(char *buf);

#endif
