#include "main.h"
/**
 * print_percent - prints percent
 * @list: integer
 * Return: 0
 */
int print_percent(va_list list)
{
	(void)list;
	_putchar('%');
	return (1);
}
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
/**
 * print_string_upper - prints a string
 * @list: va_list containing the string to print
 * Return: Always 0 || 1
 */
int print_string_upper(va_list list)
{
	char *str = va_arg(list, char *);

	if (str == NULL)
		return (0);
	while (*str)
	{
		if ((*str < 32 && *str > 0)|| *str >= 127)
		{
			_puts("\\x0");
			hex_div(*str, 1);
		}
		else
			return (0);
		str++;
	}
	return (1);
}
/**
 * print_address - prints the address of a variable
 * @list: va_list containing argument to print
 * Return: Always 1
 */
int print_address(va_list list)
{
	void *addr = va_arg(list, void *);
	unsigned long ad;

	if (!addr)
	{
		_puts("(nil)");
		return (1);
	}
	ad = (unsigned long int)addr;
	_puts("0x");
	hex_div(ad, 0);
	return (1);
}
