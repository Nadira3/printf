#include "main.h"
/**
 * printchar - prints a character from a variable list
 * @buf_ptr: buffer
 * @string: variable list
 * Return: 1
 */
size_t printchar(va_list string, char *buf_ptr)
{
	size_t len = 0;
	int character = va_arg(string, int);
	char buf_item = character;

	*buf_ptr = buf_item;
	buf_ptr++;
	len++;
	return (len);
}
/**
 * printstring - prints a string from a variable list
 * @buf_ptr: buffer
 * @string: variable list
 * Return: length of string
 */
size_t printstring(va_list string, char *buf_ptr)
{
	char *ptr = va_arg(string, char *);
	size_t len = 0;

	while (*ptr) 
	{
		*buf_ptr = *ptr;
		ptr++;
		buf_ptr++;
		len++;
	}

	*buf_ptr = '\0';
	return (len);
}
/**
 * buf_init - initializes the buffer
 * @buf: buffer
 * Return: pointer to buffer
 */
char *buf_init(char *buf)
{
	int i = 0;

	while (i < BUF_SIZE)
	{
		buf[i] = 0;
		i++;
	}

	return (buf);
}
/**
 * _printf - prints characters and strings
 * @format: format specifiers
 * Return: int
 */
int _printf(const char *format, ...) 
{
	va_list string;
	char buf[BUF_SIZE], *mv;
	size_t len, i = 0;

	va_start(string, format);
	mv = buf_init(buf);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				len = printchar(string, mv);
			else if (format[i + 1] == 's')
				len = printstring(string, mv);
			else if (format[i + 1] == '%')
			{
				buf[i] = '%';
				len = 1;
			}
			else
			{
				write(2, "Invalid Conversion Specifier\n", 29);
				return (1);
			}
			i += 2;
			mv += len;
			continue;
		}

		*mv = format[i];
		mv++;
		i++;
	}

	*mv = '\0';

	va_end(string);
	write(1, buf, mv - buf);
	return (mv - buf);
}
int main(void)
{
	_printf("%K\n");
	return (0);
}
