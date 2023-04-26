#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len = 0, len2 = 0;

	len = _printf("%!\n");
	_printf("%X\n", -1024);
	_printf("%x\n", -1024);
	printf("%x\n", 1024);
	_printf("%x\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
/*

2

```#include <stdio.h>
#include <stdlib.h>
#include "main.h"

*
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 *
int main(void)
{
	int len, len2;

	len = _printf("%K\n");
	len2 = printf("%K\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}*/