#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int d_len = s21_strlen(dest);
  const char *symb = (char *)src;
  int i = 0;
  for (; i < (int)n && *symb; i++, symb++) {
    dest[d_len + i] = src[i];
  }
  dest[d_len + i] = '\0';
  return dest;
}
