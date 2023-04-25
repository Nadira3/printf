#include "main.h"
/**
 * print_int - prints integer
 * @n: integer
 * Return: int
 */
int _puti(int n)
{
	static char buf[BUFSIZE];
	static int i;

	if (i >= BUFSIZE || n == -1)
	{
		write(1, buf, i);
		i = 0;
	}	
	buf[i] = n + '0';
	buf_count(1);
	i++;
	return (0);
}
void split_num(int n)
{
	if (n / 10)
		split_num(n / 10);
	_puti(n % 10);
}
void print_int(va_list list)
{
	int n = va_arg(list, int);
	
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	split_num(n);
	_puti(-1);
	buf_count(-1);
}
