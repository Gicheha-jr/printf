#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

int _printf(const char *format, ...)
{
    va_list args;

        int count;
        char *s;
        int c;
	
	va_start(args, format);
        count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            if (*format == 'c') {
		c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's') {
		s = va_arg(args, char *);
                fputs(s, stdout);
                count += strlen(s);
            }
            else if (*format == '%') {
                putchar('%');
                count++;
            }
        }
	else {
		putchar(*format);
		count++;
	}

	format++;
	}

	va_end(args);

	return count;
}

int main()
{
	_printf("Character: %c\n", 'A');
	_printf("String: %s\n", "Hello, World!");
	_printf("Percentage: %%\n");

	return 0;
}
