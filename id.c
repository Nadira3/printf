#include "main.h"
/**
 * print_int - prints integer
 * @n: integer
 * Return: int
 */
int _puti(int n)
{
	static char buf[BUFSIZE], i;

	if (i >= BUFSIZE || n == -1)
	{
		write(1, buf, i);
		i = 0;
	}	
	buf[i] = n + '0';
	buf_count(1);
	i++;
}
int split_num(int n)
{
	if (n / 10)
		split_num(n / 10);
	_puti(n % 10);
}
void print_int(va_list list)
{
	int len = 0;
	int n = va_arg(list, int);
	
	split_num(n);
	if (n < 0)
		write(1, "-", 1);
	_puti(-1);
	len = buf_count(0);
	buf_count(-1);
}
