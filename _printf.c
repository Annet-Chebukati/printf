#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				count += putchar('%');
			}
			else if (*format == 'c')
			{
				count += putchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				count += puts(va_arg(args, char *));
			}
			else
			{
				count += putchar('%');
				count += putchar(*format);
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}
