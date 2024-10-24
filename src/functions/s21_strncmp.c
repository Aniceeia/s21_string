#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  const char *p_str1 = str1;
  const char *p_str2 = str2;
  for (int i = 0; i < (int)n && !result && *p_str1 != '\0' && *p_str2 != '\0';
       i++) {
    if (p_str1[i] != p_str2[i]) {
      result = p_str1[i] - p_str2[i];
    }
  }
  return result;
}
