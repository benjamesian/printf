#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * struct spec - conversion specifiers and their associated functions
 *
 * @s: conversion specifier
 * @f: function associated with s
 */
typedef struct spec
{
	char *s;
	int (*f)(va_list, char *, int *, int *);
} spec_t;

int _printf(const char *format, ...);
int (*get_type(char *))(va_list, char *, int *, int *);
int print(char *, size_t);

int is_valid_specifier_char(char c);
int get_substring_length(const char *s);
int get_specifier_length(const char *s);
int get_printable_length(const char *s);

int ctoa(va_list valist, char *buffer, int *pos, int *n_printed);
int stoa(va_list valist, char *buffer, int *pos, int *n_printed);
int ntoa(va_list valist, char *buffer, int *pos, int *n_printed);
int pcttoa(va_list valist, char *buffer, int *pos, int *n_printed);
int storot13(va_list valist, char *buffer, int *pos, int *n_printed);
int storev(va_list valist, char *buffer, int *pos, int *n_printed);
int btoa(va_list valist, char *buffer, int *pos, int *n_printed);
int otoa(va_list valist, char *buffer, int *pos, int *n_printed);
int xtoa(va_list valist, char *buffer, int *pos, int *n_printed);
int Xtoa(va_list valist, char *buffer, int *pos, int *n_printed);

void buffer_full(char *buffer, int *pos, int *n_printed);
void string_to_buffer(char *s, char *buffer, int *pos, int *n_printed);

int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);

#endif
