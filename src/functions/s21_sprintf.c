#include "../s21_string.h"

extern Flags flag;
Flags flag = {'\0'};

#define REBASE(val, base, iter, str)            \
  do {                                          \
    iter--;                                     \
    str[iter] = "0123456789abcdef"[val % base]; \
    val /= base;                                \
  } while (val > 0)

char s21_type_char(va_list va) {
  char chr = va_arg(va, int);
  return chr;
}

wchar_t s21_type_wchar_t(va_list va) {
  wchar_t chr = va_arg(va, wchar_t);
  return chr;
}

void s21_string_char(char *str_copy, char *str) {
  s21_strncpy(str_copy, str, s21_strlen(str));
}

void s21_string_wchar_t(char *str_copy, wchar_t *str) {
  char str_wchar[EIGHT_KB] = {'\0'};
  wcstombs(str_wchar, str, EIGHT_KB);
  s21_strncpy(str_copy, str_wchar, s21_strlen(str_wchar));
}

#define S21_CONVERT_CHAR(TypeName)                          \
  void s21_convert_##TypeName(char *temp, va_list va) {     \
    TypeName chr = s21_type_##TypeName(va);                 \
    if (!flag.minus && flag.width) {                        \
      s21_##TypeName(temp, chr);                            \
      for (int i = 0; i < flag.width; i++) {                \
        temp[i] = ' ';                                      \
        if (i == flag.width - 1) {                          \
          temp[i] = chr;                                    \
        }                                                   \
      }                                                     \
    } else if (flag.width) {                                \
      s21_##TypeName(temp, chr);                            \
      for (int i = s21_strlen(temp); i < flag.width; i++) { \
        temp[i] = ' ';                                      \
      }                                                     \
    } else {                                                \
      s21_##TypeName(temp, chr);                            \
    }                                                       \
  }

#define S21_CONVERS_STRING_CHAR(TypeName)                         \
  void s21_convert_string_##TypeName(char *temp, TypeName *str) { \
    char str_copy[EIGHT_KB] = {'\0'};                             \
    s21_string_##TypeName(str_copy, str);                         \
    if (flag.find_dot) {                                          \
      str_copy[flag.precision] = '\0';                            \
    }                                                             \
    int shift = flag.width - s21_strlen(str_copy);                \
    int len = s21_strlen(str_copy);                               \
    if (flag.minus && shift > 0) {                                \
      s21_strncpy(temp, str_copy, s21_strlen(str_copy));          \
      s21_memset(temp + len, ' ', shift);                         \
    } else if (shift > 0) {                                       \
      s21_memset(temp, ' ', shift);                               \
      s21_strncpy(temp + shift, str_copy, s21_strlen(str_copy));  \
    } else {                                                      \
      s21_strncpy(temp, str_copy, s21_strlen(str_copy));          \
    }                                                             \
  }

#define s21_char(temp, chr)        \
  do {                             \
    s21_memset(temp, 0, EIGHT_KB); \
    temp[0] = chr;                 \
    temp[1] = '\0';                \
  } while (0)

#define s21_wchar_t(temp, wide_chr) \
  do {                              \
    s21_memset(temp, 0, EIGHT_KB);  \
    temp[0] = chr;                  \
    temp[1] = '\0';                 \
  } while (0)

#define s21_adjust_int64_t(val, type) \
  do {                                \
    switch (flag.length) {            \
      case 'h':                       \
        val = (int16_t)val;           \
        break;                        \
      case 'l':                       \
        val = (int64_t)val;           \
        break;                        \
      case 0:                         \
        val = (int32_t)val;           \
        break;                        \
    }                                 \
  } while (0)

#define s21_adjust_uint64_t(val, type) \
  do {                                 \
    switch (flag.length) {             \
      case 'h':                        \
        val = (uint16_t)val;           \
        break;                         \
      case 'l':                        \
        val = (uint64_t)val;           \
        break;                         \
      case 0:                          \
        val = (uint32_t)val;           \
        break;                         \
    }                                  \
  } while (0)

#define S21_TO_STR(val, base, dest, type)            \
  do {                                               \
    s21_adjust_##type(val, type);                    \
    char str[EIGHT_KB] = {'\0'};                     \
    int iter = EIGHT_KB - 2;                         \
    type val_abs = (type)(val);                      \
    int neg = ((int)val < 0) ? S21_TRUE : S21_FALSE; \
    val_abs = neg ? -(val_abs) : val_abs;            \
    if (val_abs == 0) {                              \
      dest[0] = '0';                                 \
    }                                                \
    REBASE(val_abs, base, iter, str);                \
    for (int j = 0; str[iter]; iter++, j++) {        \
      if (neg && j == 0) {                           \
        dest[j++] = '-';                             \
      }                                              \
      dest[j] = str[iter];                           \
    }                                                \
  } while (0)

#define S21_POINT_TO_STR(val, base, dest, type) \
  do {                                          \
    s21_adjust_##type(val, type);               \
    type val_abs = (type)(val);                 \
    char str[EIGHT_KB] = {'\0'};                \
    int iter = EIGHT_KB - 1;                    \
    REBASE(val_abs, base, iter, str);           \
    str[EIGHT_KB - 1] = '\0';                   \
    for (int j = 0; str[iter]; iter++, j++) {   \
      dest[j] = str[iter];                      \
    }                                           \
  } while (0)

#define S21_DBL_TO_STR(val, dest)                                           \
  do {                                                                      \
    char temp[EIGHT_KB] = {'\0'};                                           \
    int iter = EIGHT_KB - 2;                                                \
    int neg = (val) < 0 ? S21_TRUE : S21_FALSE;                             \
    val = neg ? (val) * -1 : (val);                                         \
    long double l = 0, r = modfl(val, &l);                                  \
    if (flag.precision == 0) {                                              \
      l = roundl(val);                                                      \
      r = 0;                                                                \
    }                                                                       \
    char right_part[EIGHT_KB] = {'\0'};                                     \
    for (int i = 0; i < flag.precision; i++) {                              \
      r = r * 10;                                                           \
      right_part[i] = (int)r + '0';                                         \
    }                                                                       \
    long long right = roundl(r), left = l;                                  \
    if (!right) {                                                           \
      for (int i = 0; i < flag.precision; iter--, i++) temp[iter] = '0';    \
    } else {                                                                \
      for (int i = s21_strlen(right_part); right || i > 0;                  \
           right /= 10, iter--, i--)                                        \
        temp[iter] = (int)(right % 10 + 0.05) + '0';                        \
    }                                                                       \
    if ((flag.find_dot && flag.precision != 0) || (int)r ||                 \
        (!flag.find_dot && val == 0) || s21_strlen(right_part))             \
      temp[iter--] = '.';                                                   \
    if (!left) {                                                            \
      temp[iter] = '0';                                                     \
      iter--;                                                               \
    } else {                                                                \
      for (; left; left /= 10, iter--) temp[iter] = (int)(left % 10) + '0'; \
    }                                                                       \
    for (int i = 0; temp[iter + 1]; iter++, i++) {                          \
      if (neg && i == 0) {                                                  \
        dest[i] = '-';                                                      \
        i++;                                                                \
      }                                                                     \
      dest[i] = temp[iter + 1];                                             \
    }                                                                       \
  } while (0)

S21_CONVERT_CHAR(char);
S21_CONVERT_CHAR(wchar_t);
S21_CONVERS_STRING_CHAR(char);
S21_CONVERS_STRING_CHAR(wchar_t);

void s21_int_logic(char *temp, va_list va) {
  int64_t val = va_arg(va, int64_t);
  S21_TO_STR(val, 10, temp, int64_t);
  s21_adjust_precision(temp);
  s21_adjust_flags(temp);
}
void s21_unsigned_logic(char *temp, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  S21_TO_STR(val, 10, temp, uint64_t);
  s21_adjust_precision(temp);
  s21_adjust_flags(temp);
}
void s21_octal_logic(char *temp, va_list va) {
  temp[0] = '0';
  uint32_t val = va_arg(va, int64_t);
  temp += flag.hash;
  S21_TO_STR(val, 8, temp, int64_t);
  s21_adjust_precision(temp);
  s21_adjust_flags(temp);
}
void s21_hexal_logic(char *temp, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  S21_TO_STR(val, 16, temp, uint64_t);
  s21_adjust_precision(temp);
  if (flag.hash) {
    s21_adjust_hexal(temp);
  }
  s21_adjust_flags(temp);
  val = 0;
}
void s21_pointer_logic(char *temp, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  flag.length = 'l';
  S21_POINT_TO_STR(val, 16, temp, uint64_t);
  s21_adjust_hexal(temp);
}
void s21_char_logic(char *temp, va_list va) {
  if (flag.length == 'l') {
    s21_convert_wchar_t(temp, va);
  } else {
    s21_convert_char(temp, va);
  }
}
void s21_string_logic(char *temp, va_list va) {
  if (flag.length == 'l') {
    wchar_t *wide_str = va_arg(va, wchar_t *);
    s21_convert_string_wchar_t(temp, wide_str);
  } else {
    char *str = va_arg(va, char *);
    s21_convert_string_char(temp, str);
  }
}
void s21_float_logic(char *str, va_list va) {
  long double val = s21_adjust_double(va);
  S21_DBL_TO_STR(val, str);
  s21_adjust_flags(str);
}
void s21_exp_logic(char *str, va_list va) {
  long double val = s21_adjust_double(va);
  int pow = 0;
  char sign = 0;
  if ((int)val) {
    sign = '+';
  } else {
    sign = '-';
  }
  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }
  S21_DBL_TO_STR(val, str);
  s21_adjust_exp(str, pow, sign);
  s21_adjust_flags(str);
}

void s21_g_logic(char *str, va_list va) {
  int pow = 0;
  long double val = s21_adjust_double(va);
  long double expon_val = val;
  int prc = flag.precision;
  if (!flag.precision) {
    flag.precision = 1;
  }
  if ((int)val - val) {
    while ((int)expon_val == 0) {
      pow++;
      expon_val *= 10;
    }
  }
  if (pow > 4) {
    flag.precision = 0;
    S21_DBL_TO_STR(expon_val, str);
  } else {
    flag.precision = 10;
    S21_DBL_TO_STR(val, str);
  }
  s21_adjust_g(str, prc);
  if (pow > 4) {
    char sign = '-';
    s21_adjust_exp(str, pow, sign);
  }
  s21_delete_zeroes(str);
  s21_adjust_flags(str);
}

long double s21_adjust_double(va_list va) {
  long double val = 0;
  if (flag.length == 'L') {
    val = va_arg(va, long double);
  } else {
    val = va_arg(va, double);
  }
  if (!flag.find_dot) {
    flag.precision = 6;
  }
  return val;
}
void s21_adjust_precision(char *dest) {
  char temp[EIGHT_KB] = {'\0'};
  int neg = S21_FALSE;
  int len = s21_strlen(dest);
  if (dest[0] == '-') {
    temp[0] = '-';
    len--;
    neg = S21_TRUE;
  }
  if (flag.precision > len) {
    int iter;
    for (iter = neg; iter < flag.precision - len + neg; iter++) {
      temp[iter] = '0';
    }
    for (int i = neg; dest[i]; i++, iter++) {
      temp[iter] = dest[i];
    }
    s21_strncpy(dest, temp, s21_strlen(temp));
  }
  if (flag.find_dot && flag.precision == 0 && temp[0] == '0') {
    dest[0] = '\0';
  }
}
void s21_adjust_flags(char *temp) {
  char str_copy[EIGHT_KB + 1] = {'\0'};
  if (flag.plus && flag.specifier != 'u') {
    str_copy[0] = temp[0] == '-' ? temp[0] : '+';
    int neg = temp[0] == '-' ? 1 : 0;
    s21_strncpy(str_copy + 1, temp + neg, s21_strlen(temp + neg));
    s21_strncpy(temp, str_copy, s21_strlen(str_copy));
  } else if (flag.space && temp[0] != '-' && flag.specifier != 'u') {
    str_copy[0] = ' ';
    s21_strncpy(str_copy + 1, temp, s21_strlen(temp));
    s21_strncpy(temp, str_copy, s21_strlen(str_copy));
  }
  if (flag.width > (int)s21_strlen(temp)) {
    int iter = flag.width - s21_strlen(temp);
    if (!flag.minus) {
      s21_memset(str_copy, flag.zero ? '0' : ' ', iter);
      s21_strncpy(str_copy + iter, temp, s21_strlen(temp));
    } else {
      s21_strncpy(str_copy, temp, s21_strlen(temp));
      s21_memset(str_copy + s21_strlen(str_copy), ' ', iter);
    }
    s21_strncpy(temp, str_copy, s21_strlen(str_copy));
  }
}
void s21_adjust_hexal(char *temp) {
  if (!s21_val_zero(temp) || flag.specifier == 'p') {
    for (int i = s21_strlen(temp); i >= 0; i--) {
      temp[i + 2] = temp[i];
    }
    temp[0] = '0';
    temp[1] = 'x';
  }
}

void s21_adjust_exp(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = pow % 10 + '0';
  pow /= 10;
  str[len + 2] = pow % 10 + '0';
  str[len + 4] = '\0';
}

void s21_adjust_g(char *str, int precision) {
  int val = 0;
  int is_zero = S21_FALSE;
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    if ((str[i] == '0' && !is_zero) || str[i] == '.') {
      continue;
    } else {
      is_zero = S21_TRUE;
    }
    if (s21_isdigit(str[i]) && is_zero) {
      val++;
    }
    if (val == precision && (i + 1) < (int)s21_strlen(str)) {
      int next = 0;
      if (str[i + 1] == '.') {
        next = 2;
      } else {
        next = 1;
      }
      if (str[i + next] - '0' > 5) {
        str[i] = (char)(str[i] + 1);
      }
      str[i + 1] = '\0';
      break;
    }
  }
}
int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }
void s21_reset_flags() {
  flag.minus = 0;
  flag.plus = 0;
  flag.space = 0;
  flag.zero = 0;
  flag.hash = 0;
  flag.precision = 0;
  flag.find_dot = 0;
  flag.width = 0;
  flag.length = 0;
  flag.specifier = 0;
}

void s21_delete_zeroes(char *str) {
  char *pt = s21_strchr(str, '.');
  if (pt) {
    for (int i = s21_strlen(str) - 1; str[i] != '.'; i--) {
      if (str[i] == '0') {
        str[i] = '\0';
      } else {
        break;
      }
    }
    if (pt[1] == '\0') {
      pt[0] = '\0';
    }
  }
}

int s21_val_zero(char *temp) {
  int result = S21_FALSE;
  for (int i = 0; temp[i]; i++) {
    if (temp[i] != '0') {
      result = S21_FALSE;
    } else {
      result = S21_TRUE;
    }
  }
  return result;
}
int s21_atoi(const char *str) {
  int result = 0, sign = 1, overflow = S21_FALSE;
  while (*str == ' ') str++;
  if (*str == '-') {
    str++;
    sign = -1;
  }
  if (*str == '+') {
    str++;
  }
  while (*str && s21_isdigit(*str)) {
    result = result * 10 + (*str - '0');
    if (result < 0) {
      overflow = S21_TRUE;
      break;
    }
    str++;
  }
  if (overflow)
    result = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    result *= sign;
  return result;
}
void s21_handle_flags(const char **format) {
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '0' || **format == '#') {
    switch (**format) {
      case '-':
        flag.minus = 1;
        break;
      case '+':
        flag.plus = 1;
        break;
      case ' ':
        flag.space = 1;
        break;
      case '0':
        flag.zero = 1;
        break;
      case '#':
        flag.hash = 1;
        break;
    }
    (*format)++;
  }
}
void s21_handle_width(const char **format, va_list va) {
  if (**format == '*') {
    (*format)++;
    flag.width = va_arg(va, int);
  } else if (s21_isdigit(*(*format))) {
    char str_copy[EIGHT_KB] = {'\0'};
    for (int i = 0; s21_isdigit(*(*format)); i++, (*format)++)
      str_copy[i] = *(*format);
    flag.width = s21_atoi(str_copy);
  }
}
void s21_handle_precision(const char **format, va_list va) {
  if (**format == '.') {
    flag.find_dot = S21_TRUE;
    (*format)++;
    if (**format == '*') {
      (*format)++;
      flag.precision = va_arg(va, int);
    }
    if (s21_isdigit(*(*format))) {
      char str_copy[EIGHT_KB] = {'\0'};
      for (int i = 0; s21_isdigit(**format); i++, (*format)++)
        str_copy[i] = *(*format);
      flag.precision = s21_atoi(str_copy);
    }
  }
}
void s21_handle_length(const char **format) {
  if (**format == 'h') {
    flag.length = 'h';
    (*format)++;
  } else if (**format == 'l') {
    flag.length = 'l';
    (*format)++;
  } else if (**format == 'L') {
    flag.length = 'L';
    (*format)++;
  }
}

void s21_handle_numeric(const char **format, char *temp, va_list va) {
  switch (**format) {
    case 'd':
      s21_int_logic(temp, va);
      break;
    case 'u':
      s21_unsigned_logic(temp, va);
      break;
    case 'o':
      s21_octal_logic(temp, va);
      break;
    case 'x':
      s21_hexal_logic(temp, va);
      break;
    case 'X':
      s21_hexal_logic(temp, va);
      char *str_copy_X = s21_to_upper(temp);
      s21_strncpy(temp, str_copy_X, s21_strlen(str_copy_X));
      free(str_copy_X);
      break;
    case 'f':
      s21_float_logic(temp, va);
      break;
    case 'e':
      s21_exp_logic(temp, va);
      break;
    case 'E':
      s21_exp_logic(temp, va);
      char *str_copy_E = s21_to_upper(temp);
      s21_strncpy(temp, str_copy_E, s21_strlen(str_copy_E));
      free(str_copy_E);
      break;
    case 'g':
      s21_g_logic(temp, va);
      break;
    case 'G':
      s21_g_logic(temp, va);
      char *str_copy_G = s21_to_upper(temp);
      s21_strncpy(temp, str_copy_G, s21_strlen(str_copy_G));
      free(str_copy_G);
      break;
  }
}

void s21_handle_char(const char **format, char *temp, va_list va) {
  switch (**format) {
    case 'c':
      s21_char_logic(temp, va);
      break;
    case 's':
      s21_string_logic(temp, va);
      break;
  }
}

void s21_handle_specifiers(const char **format, char *temp, va_list va) {
  if (s21_strchr("duoxXfeEgG", **format))
    s21_handle_numeric(format, temp, va);
  else if (s21_strchr("cs", **format))
    s21_handle_char(format, temp, va);
  else if (**format == '%')
    temp[0] = '%';
  else if (**format == 'p')
    s21_pointer_logic(temp, va);
  s21_reset_flags();
  (*format)++;
}

void s21_parser(const char **format, char *temp, va_list va) {
  s21_reset_flags();
  s21_handle_flags(format);
  s21_handle_width(format, va);
  s21_handle_precision(format, va);
  s21_handle_length(format);
  s21_handle_specifiers(format, temp, va);
}

int s21_sprintf_logic(char *str, const char *format, va_list va) {
  s21_reset_flags();
  char *str_copy = str;
  char temp[EIGHT_KB] = {'\0'};
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    }
    format++;
    s21_parser(&format, temp, va);
    for (int i = 0; temp[i]; i++, str++) {
      *str = temp[i];
    }
    if (flag.specifier == 'n') {
      int *dest = va_arg(va, int *);
      *dest = str - str_copy;
    }
  }
  *str = '\0';
  s21_memset(str, 0, s21_strlen(str));
  return s21_strlen(str_copy);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  int result = s21_sprintf_logic(str, format, va);
  va_end(va);
  return result;
}
