#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%b\n", -429496);
	/*len = _printf("%K\n");
	len2 = _printf("%!\n");
	printf("%d, %d", len, len2);
	_printf("%c", '\0');
	_printf(NULL);*/
	_printf("%c", '\0');
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", NULL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (0);
	}
	return (1);
}
