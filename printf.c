#include "main.h"
/**
 * print_char - prints a character
 * @list: va_list containing the character to print
 */
void print_char(va_list list)
{
	unsigned int ch = va_arg(list, int);

	if (ch)
		_putchar(ch);
}

/**
 * print_string - prints a string
 * @list: va_list containing the string to print
 */
void print_string(va_list list)
{
	char *ch = va_arg(list, char *);

	if (ch)
	{
		while (*ch)
		{
			_putchar(*ch);
			ch++;
		}
	}
}
/**
 * get_format - gets the format specificier of the variable argument
 * @ch: character to match with
 * Return: function pointer
 */
void (*get_format(char ch))(va_list)
{
	int j = 0;

	specifier csp[] = {
		{"c", print_char},
		{"s", print_string},
		{"S", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{NULL, NULL}
	};

	while (csp[j].f)
	{
		if (*(csp[j].f) == ch)
			return (csp[j].func);
		j++;
	}
	return (csp[j].func);
}
/**
 * _printf - prints strings and characters
 * @format: format string
 * Return: lenght of the string
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, len = 0;
	void (*func_ptr)(va_list);

	if (!format)
		return (-1);
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				func_ptr = get_format(format[i]);
				if (func_ptr)
					func_ptr(list);
				else if (format[i] == '%')
					_putchar('%');
				else
				{
					buf_count(-1);
					return (-1);
				}
				i++;
			}
			else
				return (-1);
			continue;
		}
		_putchar(format[i]);
		i++;
	}
	_putchar(format[i]);
	len += buf_count(0);
	buf_count(-1);
	return (len);
}
