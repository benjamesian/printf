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

char *ctoa(va_list);
char *stoa(va_list);
char *ntoa(va_list);
char *pcttoa(va_list);
char *storot13(va_list valist);
char *storev(va_list valist);

int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);

#endif
