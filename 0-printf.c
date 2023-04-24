#ifndef _PRINTF0_H
#define _PRINTF0_H
#include "main.h"

/**
 * print_char - Prints va_list characters
 * @args: contains the character to print
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
/**
 * print_string - Prints va_list strings
 * @args: contains the string to print
 * Return: The number of characters
 */
int print_string(va_list args)
{
	int i;
	int count = 0;
	char *str = va_arg(args, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		count += _putchar(str[i]);
	}
	return (count);
}
/**
 * _printf - Prints formatted output
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				count += print_char(args);
			}
			else if (format[i] == 's')
			{
				count += print_string(args);
			}
			else if (format[i] == '%')
			{
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
	}
	va_end(args);
	return (count);
}
#endif
