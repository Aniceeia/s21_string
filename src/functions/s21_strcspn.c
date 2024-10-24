#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int count = 0, equal = S21_FALSE;
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
      count++;
    } else {
      break;
    }
  }
  return count;
}