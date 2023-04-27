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
/**
 * print_string_upper - prints a string
 * @list: va_list containing the string to print
 * Return: Always 0 || 1
 */
int print_string_upper(va_list list)
{
	char *ch = va_arg(list, char *);

	if (ch == NULL)
		return (0);
	while (*ch)
	{
		if (*ch < 32 || *ch >= 127)
		{
			_printf("\\x0%X", *ch);
		}
		else
			_putchar(*ch);
		ch++;
	}
	return (1);
}
