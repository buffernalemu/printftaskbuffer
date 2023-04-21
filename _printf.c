#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"


int _printf(char *format, ...) {
long unsigned int i;
  va_list args;
  int found_spec;
  FormatSpec format_specs[] = {
  {'c', print_char},
  {'s', print_string},
  {'i', print_int},
  {'x', print_hex},
};

  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      found_spec = 0;
      for (i = 0; i < sizeof(format_specs) / sizeof(FormatSpec); i++) {
        if (format_specs[i].spec == *format) {
          format_specs[i].print(args);
          found_spec = 1;
          break;
        }
      }
      if (!found_spec) {
        write(1, "Invalid format specifier\n", 25);
      }
    } else {
      write(1, format, 1);
    }
    format++;
  }

  va_end(args);
  return (0);
  }
