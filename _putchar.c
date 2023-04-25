#include "main.h"
/**
 * _putchar - puts a character to output buffer
 * @str: character
 * Return: 0
 */
int _putchar(char str)
{
	static int len = 0;
	static char buf[BUFSIZE];

	if (len >= BUFSIZE || !str)
	{
		write(1, buf, len);
		len = 0;
		if (!str)
			buf_flush(buf);
		return (0);
	}
	buf[len] = str;
	len++;
	buf_count(1);
	return (0);
}
/**
 * buf_count - saves the lenght of the buffer
 * @len: initial lenght
 * Return: lenght of buffer
 */
int buf_count(int len)
{
	static int total_len = 0;

	total_len += len;
	if (len == -1)
		total_len = 0;
	return (total_len);
}
/**
 * buf_flush - flushes a buffer
 * @buf: buffer
 */
void buf_flush(char *buf)
{
	while (*buf)
	{
		*buf = '\0';
		buf++;
	}
}
