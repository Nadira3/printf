#include "main.h"
size_t (*get_format(const char *s))(va_list list)
{
	int i = 0;

	specifier cs[] = {
		{"c", printchar},
		{"s", printstring},
		{NULL, NULL}
	};
	while (cs[i].f)
	{
		if (*(cs[i].f) == *s)
			return (cs[i].func);
		i++;
	}
	return (cs[i].func);
}
size_t printchar(va_list list)
{
	size_t len = 0;
	int c = va_arg(list, int);

	_putchar(c);
	len++;
	return (len);
}
size_t printstring (va_list list)
{
	size_t len = 0;
	char *string = va_arg(list, char *);
	
	while (*string)
	{
		_putchar(*string);
		string++;
		len++;
	}
	return (len);
}
int _printf(const char *format, ...)
{
	va_list list;
	size_t i = 0;
	int len = 0;
	size_t (*format_func)(va_list) = NULL;

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i - 1] != '%')
		{
			i++;
			continue;
		}
		if (format[i - 1] == '%')
		{
			if (format[i] != '%')
				format_func = get_format(&format[i]);
			else
				len += _putchar('%');
			if (format_func)
				len = format_func(list);
			else if (!format_func && format[i] != '%')
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		len += _putchar(format[i]);
		i++;
	}
	len += _putchar(format[i]);
	printf("%d\n", len);
	va_end(list);
	return (i + len);
}
