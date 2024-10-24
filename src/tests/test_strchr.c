#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strchr_test) {
  char str1[] = "Abcdefg";
  char str2[] = "Abcdefg";

  int symbol1 = 'd';
  int symbol2 = 'd';

  char *ach1 = s21_strchr(str1, symbol1);
  char *ach2 = strchr(str2, symbol2);

  ck_assert_str_eq(ach1, "defg");
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *strchr_suite() {
  Suite *s = suite_create("strchr_suite");
  TCase *core = tcase_create("strchr_suite");

  tcase_add_test(core, strchr_test);
  suite_add_tcase(s, core);

  return s;
}