#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) void(x)
#define BUFF_SIZE 1024

#define F_HASH 8

#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);
void buffer(char array[], int *arr_index);
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
long int convert_nr(long in nr, int size);
long int convert_specific(unsigned long int nr, int size);

#endif
