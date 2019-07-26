#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>

/**
 * struct spec - conversion specifiers and their associated functions
 *
 * @s: conversion specifier
 * @f: function associated with s
 */
typedef struct spec
{
	char *s;
	char *(*f)(int, ...);
} spec_t;

int _printf(const char *format, ...);
char *(*get_type(char *))(unsigned int, ...);
int print(char *);

char *ctoa(char);
char *itoa(int);

#endif