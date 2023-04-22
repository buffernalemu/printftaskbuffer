#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void print_char(va_list args) {
  
    char c;
    printf("actual function is called\n");
  c = va_arg(args, int);
  write(1, &c, sizeof(char));
}

void print_string(va_list args) {
char *s;
size_t len;
printf("actual function is called");
  s = (char*) va_arg(args, char*);
  len = 0;
  while (s[len] != '\0') {
    len++;
  }
  write(1, s, len);
}

void print_int(va_list args) {
int i;
char *buf;
int len;
  i = va_arg(args, int);
  printf("actual function is called");
  buf = (char*) malloc(32 * sizeof(char));
  len = sprintf(buf, "%d", i);
  write(1, buf, len);
  free(buf);
}

void print_hex(va_list args) {
int i;
char *buf;
int len;
printf("actual function is called");
  i = va_arg(args, int);
  buf = (char*) malloc(32 * sizeof(char));
  len = sprintf(buf, "%x", i);
  write(1, buf, len);
  free(buf);
}