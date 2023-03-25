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
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'u':
					count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%X", va_arg(args, unsigned int));
					break;
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case 'p':
					count += printf("%p", va_arg(args, void *));
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

