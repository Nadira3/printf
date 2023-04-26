#include "main.h"
/**
 * octal_div - converts a number to base 8 by recursive split
 * @n: number
 */
char letter(unsigned n)
{
	char hex_array[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i = 0;

	while (i <= n)
	{
		if (n == i)
			return (hex_array[i]);
		i++;
	}
}
void hex_div(unsigned n)
{
	if (n / 16)
		hex_div(n / 16);
	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar(letter((n % 16) % 10));
}
void negative_hex_div(unsigned n)
{
	if (n / 16)
		negative_hex_div(n / 16);
	_putchar(((15 - (n % 16)) + (n / 16) ? 0 : 1) + '0');
}
/**
 * print_hex - prints integer
 * @list: variable list
 */
int print_hex(va_list list)
{
	unsigned n = va_arg(list, unsigned int);
		
	hex_div(n);
}
