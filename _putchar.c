#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes to a buffer/stdout
 * @str: character
 * Return: number of characters written
 */
int _putchar(char str)
{
	static int i = 0, len = 0;
	static char buf[BUFSIZE];
	
	if (i >= BUFSIZE || !str)
	{
		write(1, buf, i);
		len = i;
		i = 0;
		return (len);
	}
	buf[i] = str;
	i++;
	return (i);
}
