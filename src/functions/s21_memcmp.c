#include "../s21_string.h"

// str1 и str2 разные? 0 = false (одинаковые)
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *p_str1 = str1;
  const char *p_str2 = str2;

  for (int i = 0; i < (int)n && !result; i++) {
    if (p_str1[i] != p_str2[i]) {
      result = p_str1[i] - p_str2[i];
    }
  }
  return result;
}
