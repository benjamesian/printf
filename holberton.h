#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct spec - conversion specifiers and their associated functions
 *
 * @s: conversion specifier
 * @f: function associated with s
 */
typedef struct spec
{
	char *s;
	char *(*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
char *(*get_type(char *))(va_list);
int print(char *);

int is_valid_specifier_char(char c);
int get_substring_length(const char *s);
int get_specifier_length(const char *s);
int get_printable_length(const char *s);

char *ctoa(va_list);
char *stoa(va_list);
char *ntoa(va_list);
char *pcttoa(va_list);

int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);

#endif
