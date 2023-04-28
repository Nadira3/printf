#include "main.h"
/**
 * print_char - prints a character
 * @list: va_list containing the character to print
 * Return: Always 0 || 1
 */
int print_char(va_list list)
{
	unsigned int ch = va_arg(list, int);

	if (!ch)
		buf_count(-1);
	_putchar(ch);
	return (1);
}

/**
 * print_string - prints a string
 * @list: va_list containing the string to print
 * Return: Always 0 || 1
 */
int print_string(va_list list)
{
	char *ch = va_arg(list, char *);

	if (ch == NULL)
		return (0);
	while (*ch)
	{
		_putchar(*ch);
		ch++;
	}
	return (1);
}
/**
 * get_format - gets the format specifier of the variable argument
 * @ch: character to match with
 * Return: function pointer
 */
int (*get_format(char ch))(va_list)
{
	int j = 0;

	specifier csp[] = {
		{"c", print_char},
		{"s", print_string},
		{"S", print_string_upper},
		{"d", print_int},
		{"i", print_int},
		{"u", u_print_int},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex_lower},
		{"X", print_hex_upper},
		{"p", print_address},
		{NULL, NULL}
	};

	while (csp[j].f)
	{
		if (*(csp[j].f) == ch)
			return (csp[j].func);
		j++;
	}
	return (NULL); /*Here should just return NULL*/
	
}
/**
 * _printf - prints strings and characters
 * @format: format string
 * Return: length of the string
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, len = 0, (*func_ptr)(va_list);

	if (!format)
		return (-1);
	
	if (format[0] == '%' && !(get_format(format[1])))
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
				{	
					if (!(func_ptr(list)))
					{
						va_end(list);
						return (-1);
					}
				}
				else if (format[i] == '%')
					_putchar('%');
				else
				{
					buf_count(-1);
					va_end(list);
					return (-1);
				}
				i++;
			}
			else{
				return (-1);
			}
			continue;
		}
		_putchar(format[i]);
		i++;
	}
	_putchar(format[i]);
	len += buf_count(0);
	va_end(list);
	buf_count(-1);
	return (len);
}
