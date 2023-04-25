#include "main.h"
/**
 * split_num - splits a number
 * @n: number
 */
void split_num(int n)
{
	if (n / 10)
		split_num(n / 10);
	_putchar((n % 10) + '0');
}
/**
 * print_int - prints integer
 * @list: integer
 */
void print_int(va_list list)
{
	int n = va_arg(list, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	split_num(n);
}
