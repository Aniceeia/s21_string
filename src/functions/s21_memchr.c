#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int result = n;
  if (str != S21_NULL) {
    for (int i = 0; i < (int)n && result == (int)n; i++) {
      const char *p_str = str;
      if (p_str[i] == c) {
        result = i;
      }
    }
  }
  return result != (int)n ? (void *)((const char *)str + result) : S21_NULL;
}