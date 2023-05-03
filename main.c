#include "main.h"
#include <limits.h>
int main(void)
{

	_printf("%+d\n", 1024);
	_printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	_printf("% i - % i = % i\n", 1024, 2048, -1024);
	_printf("%#o\n", 0);
	_printf("%#o\n", UINT_MAX);
	_printf("%+d\n", -1024);
	_printf("%+d\n", 0);
	_printf("%+d\n", INT_MAX);
	_printf("There is %+d bytes in %+d KB\n", 1024, 1);
	_printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	return (0);
}
