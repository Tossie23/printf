#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _strlen - Computes the size of a string
 * @s: The string to compute the size of
 *
 * Return: The size of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_char_string_spec - Prints a character, string or percent sign
 * @c: The conversion specifier
 * @args: The argument list
 */
void print_char_string_spec(char c, va_list args)
{
	char *str;
	char ch;

	switch (c)
	{
		case 'c':
			ch = (char) va_arg(args, int);
			write(1, &ch, 1);
			break;
		case 's':
			str = va_arg(args, char *);
			write(1, str, _strlen(str));
			break;
		case '%':
			write(1, "%", 1);
			break;
	}
}

/**
 * _printf - Our custom printf function
 * @format: The format string
 *
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_char_string_spec(format[i], args);
		}
		else
			write(1, &format[i], 1);
		i++;
	}

	va_end(args);

	return (0);
}
