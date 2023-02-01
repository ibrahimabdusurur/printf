#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
  * _printf - format and print data.
  * @format: pointer to character string.
  * @...: the arguments passed to the function.
  *
  * Return: the number of characters printed
  *	    (excluding the null byte used to end output to strings).
  */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, char_len = 0, len = 0;
	pr_t specifiers [] = {
		{"c", print_char},
		{"s", print_str}
	};

	va_start(args, format);

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;

			if (*(format + i) == '%')
			{
				write(1, (format + i), sizeof(char));
				char_len++;
			}

			else
			{
				j = 0;

				while (j < 2 && (*(format + i) !=
					*(specifiers[j].sp)))
					j++;

				if (j < 2)
				{
					len = specifiers[j].f(args);
					char_len += len;
				}
			}
		}

		else
		{
			write(1, (format + i), sizeof(char));
			char_len++;
		}

		i++;
	}
	
	va_end(args);

	return (char_len);
}
