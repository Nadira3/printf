#include "main.h"
/**
 * octal_div - converts a number to base 8 by recursive split
 * @n: number
 */
char letter(unsigned n, int flag)
{
	char hex_array[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int i = 0;

	while (i <= n)
	{
		if (n == i)
			return (flag ? (hex_array[i] - 32) : hex_array[i]);
		i++;
	}
	return (hex_array[i]);
}
void hex_div(unsigned long n, int flag)
{
	if (n / 16)
		hex_div((n / 16), flag);
	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar(letter(((n % 16) % 10), flag));
}
void negative_hex_div(unsigned n, int flag)
{
	if (n / 16)
		negative_hex_div((n / 16), flag);
	_putchar(((15 - (n % 16)) + (n / 16) ? 0 : 1) + '0');
}
/**
 * print_hex - prints integer
 * @list: variable list
 */
int print_hex_lower(va_list list)
{
	unsigned n = va_arg(list, unsigned int);
		
	hex_div(n, 0);
	return (1);
}
/**
 * print_hex - prints integer
 * @list: variable list
 */
int print_hex_upper(va_list list)
{
	unsigned n = va_arg(list, unsigned int);
		
	hex_div(n, 1);
	return (1);
}
