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
void negative_binary_div(unsigned int n)
{
	if (n / 2)
		negative_binary_div(n / 2);
	_putchar(-((n % 2) - 1) + '0');
}
/**
 * print_binary - prints integer
 * @list: variable list
 */
void print_binary(va_list list)
{
	int n = va_arg(list, int);
	int flag = n >= 0 ? 0 : 1;

	n = n > 0 ? n : -n;
	if (!flag)
		binary_div(n);
	else
		negative_binary_div(n);
}
