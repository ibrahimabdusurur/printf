#include "main.h"

int _strlen(char *str);
int print_char(va_list args);
int print_str(va_list args);
/**
  * _strlen - finds length of the string passed to the function.
  * @str: the string passed to the function.
  *
  * Return: length of str.
  */
int _strlen(char *str)
{
	int len = 0;

	while (*(str + len))
		len++;

	return (len);
}

/**
  * print_char - prints a char.
  * @args: the argument pointing to the character to be printed.
  *
  * Return: number of character printed (1).
  */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);

	write(1, &c, sizeof(char));

	return (1);
}


/**
  * print_str - prints a string.
  * @args: the argument pointing to the string to be printed.
  *
  * Return: number of characters of the string.
  */
int print_str(va_list args)
{
	char *s;
	int len;

	s = va_arg(args, char *);
	len = _strlen(s);
	write(1, s, (sizeof(char) * len));

	return (len);
}
