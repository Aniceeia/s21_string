#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *p_dest = dest;
  const char *p_src = src;
  const char *symb = (char *)src;
  for (int i = 0; i < (int)n && *symb; i++, symb++) {
    p_dest[i] = p_src[i];
  }
  if (n < sizeof(dest)) {
    p_dest[n] = '\0';
  }
  return dest;
}
