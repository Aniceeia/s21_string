#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strncpy_test) {
  char src[] = "\0";
  char res[] = "\0";
  char exp[] = "\0";
  char src1[] = "123\0";
  char res1[] = "123\0";
  char exp1[] = "123\0";
  char src2[] = "13\0";
  char res2[] = "13\0";
  char exp2[] = "13\0";

  s21_size_t n_byte = 0;
  s21_size_t n1_byte = 0;
  s21_size_t n2_byte = 4;

  s21_strncpy(res, src, n_byte);
  s21_strncpy(res1, src1, n1_byte);
  s21_strncpy(res2, src2, n2_byte);

  strncpy(exp, src, n_byte);
  strncpy(exp1, src1, n1_byte);
  strncpy(exp2, src2, n2_byte);

  ck_assert_str_eq(res, exp);
  ck_assert_str_eq(res1, exp1);
  ck_assert_str_eq(res2, exp2);
}
END_TEST

Suite *strncpy_suite() {
  Suite *s = suite_create("strncpy_suite");
  TCase *core = tcase_create("strncpy_suite");

  tcase_add_test(core, strncpy_test);
  suite_add_tcase(s, core);

  return s;
}