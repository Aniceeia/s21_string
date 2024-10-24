#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *out = S21_NULL;
  unsigned size = 0;
  if (str) {
    size = s21_strlen(str) + 1;
    out = calloc(size, sizeof(char));
  }
  if (out) {
    for (unsigned i = 0; i < size; i++) {
      if (str[i] >= 'a' && str[i] <= 'z')
        out[i] = str[i] & ~' ';  // space = 32
      else
        out[i] = str[i];
    }
  }

  return (void *)out;  // can be NULL, free it's user problem
}

void *s21_to_lower(const char *str) {
  char *out = S21_NULL;
  unsigned size = 0;
  if (str != S21_NULL) {
    size = s21_strlen(str) + 1;
    out = calloc(size, sizeof(char));
  }
  if (out) {
    for (unsigned i = 0; i < size; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z')
        out[i] = str[i] | ' ';  // space = 32
      else
        out[i] = str[i];
    }
  }

  return (void *)out;  // can be NULL, free it's user problem
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *res = S21_NULL;
  if (src && start_index < s21_strlen(src) && str != S21_NULL) {
    res = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
  }
  if (res) {
    s21_strncpy(res, src, start_index);
    if (*str != '\0') s21_strncat(res, str, s21_strlen(str));
    s21_strncat(res, &src[start_index], s21_strlen(&src[start_index]));
  }
  return (void *)res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  char *start = S21_NULL;
  char *end = S21_NULL;

  if (src) {
    start = (char *)src;
    end = (char *)src + s21_strlen(src) - 1;
    if (trim_chars) {
      while (*start && s21_strchr(trim_chars, *start)) {
        start++;
      }
      while (end > start && s21_strchr(trim_chars, *end)) {
        end--;
      }
      res = calloc((end - start + 2), sizeof(char));
      if (res) s21_memcpy(res, start, end - start + 1);
    } else {
      res = calloc(s21_strlen(src) + 1, sizeof(char));
      if (res) s21_memcpy(res, start, end - start + 1);
    }
  }

  return (void *)res;
}
