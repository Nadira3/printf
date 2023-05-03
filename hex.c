#include "main.h"
/**
 * letter - changes hex numbers greater than 9 to letters
 * @n: number
 * @flag: checker for hex letter case
 * Return: character
 */
char letter(unsigned int n, int flag)
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
/**
 * hex_div - prints the hex of a positive number
 * @n: number
 * @flag: checker for hex letter case
 */
void hex_div(unsigned long int n, int flag)
{
	if (n / 16)
		hex_div((n / 16), flag);
	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar(letter(((n % 16) % 10), flag));
}
/**
 * negative_hex_div - prints the hex of a negative number
 * @n: number
 * @flag: checker for hex letter case
 */
void negative_hex_div(unsigned int n, int flag)
{
	if (n / 16)
		negative_hex_div((n / 16), flag);
	_putchar(((15 - (n % 16)) + (n / 16) ? 0 : 1) + '0');
}
/**
 * print_hex_lower - prints integer
 * @list: variable list
 * Return: Always 1
 */
int print_hex_lower(va_list list, char flag)
{
	unsigned int n = va_arg(list, unsigned int);

	if (flag == '#')
		_puts("0x");
	hex_div(n, 0);
	return (1);
}
/**
 * print_hex_upper - prints integer
 * @list: variable list
 * Return: Always 1
 */
int print_hex_upper(va_list list, char flag)
{
	unsigned int n = va_arg(list, unsigned int);

	if (flag == '#')
		_puts("0X");
	hex_div(n, 1);
	return (1);
}
