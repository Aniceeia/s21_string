#ifndef _S21_SPRINTF_H_
#define _S21_SPRINTF_H_

#include "s21_string.h"
#define EIGHT_KB 1024 * 8
typedef struct {
  int minus;
  int plus;
  int space;
  int zero;
  int hash;
  int precision;
  int find_dot;
  int width;
  char length;
  char specifier;
} Flags;

// specs logic
void s21_int_logic(char *temp, va_list va);
void s21_unsigned_logic(char *temp, va_list va);
void s21_octal_logic(char *temp, va_list va);
void s21_hexal_logic(char *temp, va_list va);
void s21_pointer_logic(char *temp, va_list va);
void s21_char_logic(char *temp, va_list va);
void s21_string_logic(char *temp, va_list va);
void s21_float_logic(char *str, va_list va);
void s21_exp_logic(char *str, va_list va);
void s21_g_logic(char *str, va_list va);
// calibrate output
long double s21_adjust_double(va_list va);
void s21_adjust_precision(char *temp);
void s21_adjust_flags(char *temp);
void s21_adjust_hexal(char *temp);
void s21_adjust_exp(char *str, int pow, char sign);
void s21_adjust_g(char *str, int precision);
// helpers
int s21_isdigit(char c);
void s21_reset_flags();
void s21_delete_zeroes(char *str);
int s21_val_zero(char *temp);
int s21_atoi(const char *str);
// for parser
void s21_handle_flags(const char **format);
void s21_handle_width(const char **format, va_list va);
void s21_handle_precision(const char **format, va_list va);
void s21_handle_length(const char **format);
void s21_handle_numeric(const char **format, char *temp, va_list va);
void s21_handle_specifiers(const char **format, char *temp, va_list va);
void s21_handle_char(const char **format, char *temp, va_list va);
// parser
void s21_parser(const char **format, char *temp, va_list va);
// main logic
int s21_sprintf_logic(char *str, const char *format, va_list va);
// va start, end,
int s21_sprintf(char *str, const char *format, ...);
#endif  //  _S21_SPRINTF_H_
