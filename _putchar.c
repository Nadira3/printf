#include "main.h"
/**
 * _putchar - puts a character to output buffer
 * @str: character
 * Return: 0
 */
int _putchar(char str)
{
	static int len;
	static char buf[BUFSIZE];

	if (len >= BUFSIZE || !str)
	{
		write(1, buf, len);
		len = 0;
		return (0);
	}
	buf[len] = str;
	len++;
	buf_count(1);
	return (1);
}
/**
 * buf_count - saves the lenght of the buffer
 * @len: initial lenght
 * Return: lenght of buffer
 */
int buf_count(int len)
{
	static int total_len;

	if (len == -1)
	{
		total_len = 0;
		return (total_len);
	}
	total_len += len;
	return (total_len);
}
