#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *p_str = str;
  for (int i = 0; i < (int)n; i++) {
    p_str[i] = c;
  }
  return str;
}
