#include <stdarg.h>
#include <stdio.h>
#include "main.h"


int _printf(const char *format, ...)
{
	va_list args;

	int letter_count = 0;


	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar(*format);
				letter_count++;
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				_putchar(ch);
				letter_count++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(args, char *);

				while (*string)
				{
					_putchar(*string);
					string++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int integer = va_arg(args, int);
				_putchar(integer);
				letter_count++;
			}
		}
		else
		{
			_putchar(*format);
			letter_count++;
		}


		format++;
	}


	return (letter_count);
}
