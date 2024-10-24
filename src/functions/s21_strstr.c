#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = {0};
  while (*haystack) {
    const char *p_hay = haystack;
    const char *p_nee = needle;
    while (*p_nee && *p_hay == *p_nee) {
      p_hay++;
      p_nee++;
    }
    if (!*p_nee) {
      result = (char *)haystack;
      break;
    }
    haystack++;
  }
  return result;
}
