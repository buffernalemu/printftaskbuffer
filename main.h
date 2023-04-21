#ifndef PRINT_F
#define PRINT_F

#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

typedef struct {
  char spec;
  void (*print)(va_list);
} FormatSpec;

int _printf(char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_hex(va_list args);



#endif