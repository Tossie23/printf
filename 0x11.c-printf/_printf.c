#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * _printf - A simplified version of printf.
 * @format: The format string.
 * @...: The list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			count++;
			i++; /* Skip the second '%' */
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			putchar(va_arg(args, int));
			count++;
			i++; /* Skip 'c' */
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);
			if (str != NULL)
			{
				while (*str)
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			else
			{
				printf("(null)");
				count += 6; /* "(null)" has 6 characters */
			}
			i++; /* Skip 's' */
		}
		else
		{
			putchar(format[i]); /* Print the '%' character */
			count++;
		}

		i++;
	}

	va_end(args);

	return (count);
}
