#include "main.h"
/**
 * binary_div - converts a number to base 2 by recursive split
 * @n: number
 */
void binary_div(unsigned n)
{
	if (n / 2)
		binary_div(n / 2);
	_putchar((n % 2) + '0');
}
/**
 * negative_binary_div - converts negative decimal to binary
 * @n: number
 */
void negative_binary_div(unsigned n)
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
int print_binary(va_list list)
{
	unsigned n = va_arg(list, unsigned int);

	binary_div(n);
	return (1);
}
