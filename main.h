#ifndef MAIN_H
#define MAIN_H

/* C standard library header files */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) void(x)
#define BUFF_SIZE 1024

/* flag characters */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* sizes */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - The operator for the structures
 * @fmt: format
 * @func: function
 */

struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Inpute for structure operations
 * @func: Functions associated to the fmt_t
 */
typedef struct fmt fmt_t;

int print_all(const char *fmt, int index, va_list args, char buf[],
		int flags, int width, int precision, int size);

/* function prototypes */
int _printf(const char *format, ...);
void buffer(char array[], int *arr_index);
int _putchar(char c);
int printf_i(va_list args);
int printf_d(va_list args);
int unsigned_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int octal_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int int_hex(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int upper_hexa_int(va_list types, char buffer[],
		flags, width, precision, size);
int hexa_int(va_list types, char buffer[], char map_to[],
		int flags, char flag_ch, int width, int precision, int size);
int printable(char p);
int hexa_code(char code, char array[], int j);
int verify(char d);
long int convert_nr(long int nr, int size);
long int convert_specific(unsigned long int nr, int size);
int flag_characters(const char *sent, int *p);
int width_ch(const char *str, int *argu, va_list list);
int _precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int print_all(const char *fmt, int *index, va_list args, char buf[],
		int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_non_printable(va_list args, char buffer[], int flags,
		int width, int precision, int size);
int print_reverse(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_rot13string(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int character(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int char_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int express_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int integer_argu(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int convert_to_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);

#endif /* MAIN_H */
