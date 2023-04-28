#include "main.h"
/**
 * find_rot - finds the rot13 equivalent of the member of a string and
 * puts in the buffer
 * @s: string
 */
void find_rot(char *s)
{
	if (!*s)
		return;
	if ((*s >= 65 && *s <= 77) || (*s >= 97 && *s <= 109))
		_putchar(*s + 13);
	else if ((*s >= 78 && *s <= 90) || (*s >= 110 && *s <= 122))
		_putchar(*s - 13);
	else
		_putchar(*s);
	find_rot(s + 1);
}
/**
 * print_rot13 - prints the rot13 equivalent of a string
 * @list: variable list
 * Return: integer
 */
int print_rot13(va_list list)
{
	char *str = va_arg(list, char *);

	if (!str)
		return (0);
	find_rot(str);
	return (1);
}
