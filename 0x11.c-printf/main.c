#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;

	len = _printf("Hello, world!\n");
	printf("Length: %d\n", len);

	_printf("Character: [%c]\n", 'H');
	_printf("String: [%s]\n", "Hello");
	_printf("Percent: %%\n");

	return (0);
}
