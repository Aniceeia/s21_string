#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int equal = S21_FALSE;
  while (*str1) {
    const char *p_str2 = str2;
    while (*p_str2) {
      if (*str1 == *p_str2) {
        equal = S21_TRUE;
      }
      p_str2++;
    }
    if (!equal) {
      str1++;
    } else {
      break;
    }
  }
  return equal ? (char *)str1 : S21_NULL;
}
