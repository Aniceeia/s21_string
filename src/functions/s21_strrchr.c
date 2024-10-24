#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = {0};
  int equal = S21_FALSE;
  for (; *str; str++) {
    if (*str == c) {
      result = (char *)str;
      equal = S21_TRUE;
    }
  }
  if (!equal) {
    result = (char *)str;
  }
  return *result == c ? (char *)result : S21_NULL;
}
