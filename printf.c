#include "main.h"
/**
 * flag - checks the flag of a printf call
 * @ch: character to be evaluated for flag validity
 * Return: flag if successfully matched
 */
char flag_check(char ch)
{
	char *str = "+ #";

	while (*str)
	{
		if (ch == *str)
			return (ch);
		str++;
	}
	return ('\0');
}
/**
 * print_char - prints a character
 * @list: va_list containing the character to print
 * Return: Always 0 || 1
 */
int print_char(va_list list, char __attribute__((unused)) flag)
{
	unsigned int ch = va_arg(list, int);
	(void)flag;

	if (!ch)
	{
		write(1, &ch, 1);
		buf_count(1);
	}
	_putchar(ch);
	return (1);
}

/**
 * print_string - prints a string
 * @list: va_list containing the string to print
 * Return: Always 0 || 1
 */
int print_string(va_list list, char __attribute__((unused)) flag)
{
	char *ch = va_arg(list, char *);
	int i = 0;

	if (ch == NULL)
		ch = "(null)";
	while (*ch)
	{
		_putchar(*ch);
		ch++;
		i++;
	}
	return (i);
}
/**
 * get_format - gets the format specifier of the variable argument
 * @ch: character to match with
 * Return: function pointer
 */
int (*get_format(char ch))(va_list, char flag)
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
		{"%", print_percent},
		{"r", print_rev},
		{"R", print_rot13},
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
	int i = 0, len = 0, (*func_ptr)(va_list, char);
	char flag;

	if (!format)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (flag_check(format[i]))
			{
				flag = flag_check(format[i]);
				i++;
			}
			if (!(get_format(format[i])))
			{
				i--;
				_putchar(format[i]);
				i++;
				continue;
			}
			func_ptr = get_format(format[i]);
			func_ptr(list, flag);
			i++;
			continue;
		}
		len += _putchar(format[i]);
		i++;
	}
	_putchar(format[i]);
	va_end(list);
	len = buf_count(0);
	buf_count(-1);
	return (len);
}
