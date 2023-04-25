#include "main.h"
/**
 * print_int - prints integer
 * @n: integer
 * Return: int
 */
void split_num(int n)
{
	if (n / 10)
		split_num(n / 10);
	_putchar((n % 10) + '0');
}
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
