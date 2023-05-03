#include "main.h"
/**
 * binary_div - converts a number to base 2 by recursive split
 * @n: number
 */
void binary_div(unsigned int n)
{
	if (n / 2)
		binary_div(n / 2);
	_putchar((n % 2) + '0');
}
/**
 * negative_binary_div - converts negative decimal to binary
 * @n: number
 */
void negative_binary_div(unsigned int n)
{
	if (n / 2)
		negative_binary_div(n / 2);
	_putchar(-((n % 2) - 1) + '0');
}
/**
 * print_binary - prints integer
 * @list: variable list
 * Return: Always 0 || 1
 */
int print_binary(va_list list, char flag)
{
	unsigned int n = va_arg(list, unsigned int);
	(void)flag;

	binary_div(n);
	return (1);
}
/**
 * _print_rev_recursion - prints a string, followed by a new line.
 * @s: string
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
		s--;
	}
}
/**
 * print_rev - prints a string in reverse
 * @list: variable list
 * Return: 1
 */
int print_rev(va_list list, char flag)
{
	char *str = va_arg(list, char *);
	(void)flag;

	if (!str)
		return (0);
	_print_rev_recursion(str);
	return (1);
}
