#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
  * struct pr - struct pr.
  *
  * @sp: the specifier.
  * @f: the function associated.
  */
typedef struct pr
{
	char *sp;
	int (*f)(va_list args);
}pr_t;

int _printf(const char *format, ...);
int _strlen(char *str);
int print_char(va_list args);
int print_str(va_list args);

#endif /* MAIN_H */
