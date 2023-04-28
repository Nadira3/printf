
#include "main.h"
/**
 * u_split_num - splits a number
 * @n: number
 */
void u_split_num(long int n)
{
	if (n / 10)
		split_num(n / 10);
	_putchar((n % 10) + '0');
}
/**
 * u_print_int - prints integer
 * @list: integer
 * Return: 0
 */
int u_print_int(va_list list)
{
	long int n = va_arg(list, unsigned int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	split_num(n);
	return (1);
}
/**
 * octal_div - converts a number to base 8 by recursive split
 * @n: number
 */
void octal_div(unsigned int n)
{
	if (n / 8)
		octal_div(n / 8);
	_putchar((n % 8) + '0');
}
/**
 * negative_octal_div - converts negative decimal to octal
 * @n: number
 */
void negative_octal_div(unsigned int n)
{
	if (n / 8)
		negative_octal_div(n / 8);
	_putchar((7 - (n % 8)) + '0');
}
/**
 * print_octal - prints integer
 * @list: variable list
 * Return: Always 0 || 1
 */
int print_octal(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);

	octal_div(n);
	return (1);
}
