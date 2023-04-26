#include "main.h"
/**
 * split_num - splits a number
 * @n: number
 */
void split_num(long int n)
{
	if (n / 10)
		split_num(n / 10);
	_putchar((n % 10) + '0');
}
/**
 * print_int - prints integer
 * @list: integer
 * Return: 0
 */
int print_int(va_list list)
{
	long int n = va_arg(list, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	split_num(n);
	return (1);
}
