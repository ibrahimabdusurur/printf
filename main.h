#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list args);
}specifier_t;

int _printf(const char *format, ...);
int _strlen(char *str);
int print_char(va_list args);
int print_str(va_list args);

#endif /* MAIN_H */
