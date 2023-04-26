#include "main.h"
/**
 * octal_div - converts a number to base 8 by recursive split
 * @n: number
 */
void octal_div(int n)
{
	if (n / 8)
		octal_div(n / 8);
	_putchar((n % 8) + '0');
}
void negative_octal_div(int n)
{
	if (n / 8)
		negative_octal_div(n / 8);
	_putchar(((7 - (n % 8)) + (n / 8) ? 0 : 1) + '0');
}
/**
 * print_binary - prints integer
 * @list: variable list
 */
void print_octal(va_list list)
{
	int n = va_arg(list, int);
	int flag = n >= 0 ? 0 : 1;

	n = n > 0 ? n : -n;
	if (!flag)
		octal_div(n);
	else
	{
		n = octal_div(n);
		negative_octal_div(n);
	}
}
