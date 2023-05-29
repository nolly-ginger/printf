#ifndef MAIN_H
#define MAIN_H

/* C standard library header files */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_i(va_list args);

#endif /* MAIN_H */
