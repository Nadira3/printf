
#include "main.h"
/**
 * octal_div - converts a number to base 8 by recursive split
 * @n: number
 */
void hex_div(int n)
{
	if (n / 16)
		hex_div(n / 16);
	_putchar((n % 16) + '0');
}
void negative_hex_div(int n)
{
	if (n / 16)
		negative_hex_div(n / 16);
	_putchar(((15 - (n % 16)) + (n / 16) ? 0 : 1) + '0');
}
/**
 * print_binary - prints integer
 * @list: variable list
 */
void print_hex(va_list list)
{
	int n = va_arg(list, int);
	int flag = n >= 0 ? 0 : 1;

	n = n > 0 ? n : -n;
	if (!flag)
		hex_div(n);
	else
	{
		n = hex_div(n);
		negative_hex_div(n);
	}
}
