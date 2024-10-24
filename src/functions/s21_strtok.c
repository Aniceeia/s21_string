#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *start = S21_NULL;
  char *end = {0};
  char *result = {0};
  if (str) {
    start = str;
  }
  while (start && *start) {
    while (*start && s21_strpbrk(start, delim) == start) {
      start++;
    }
    if (*start == '\0') {
      break;
    }
    end = s21_strpbrk(start, delim);
    if (end) {
      *end = '\0';
      result = start;
      start = end + 1;
    } else {
      result = start;
      start = S21_NULL;
    }
    if (*result != '\0') {
      return result;
    }
  }
  return S21_NULL;
}
