#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strstr_test) {
  char t_1[] = "<<<5>>>";
  char t_2[] = "5";
  char t_3[] = "QwertyQwertyQwerty";
  char t_4[] = "Qwerty";
  char t_5[] = "abcd";
  char t_6[] = "";
  char t_7[] = "aaaaa123aaa1234aaa";
  char t_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(t_1, t_2), strstr(t_1, t_2));
  ck_assert_ptr_eq(s21_strstr(t_3, t_4), strstr(t_3, t_4));
  ck_assert_ptr_eq(s21_strstr(t_5, t_6), strstr(t_5, t_6));
  ck_assert_ptr_eq(s21_strstr(t_4, t_5), strstr(t_4, t_5));
  ck_assert_ptr_eq(s21_strstr(t_7, t_8), strstr(t_7, t_8));
}
END_TEST

Suite *strstr_suite() {
  Suite *s = suite_create("strstr_suite");
  TCase *core = tcase_create("strstr_suite");

  tcase_add_test(core, strstr_test);
  suite_add_tcase(s, core);

  return s;
}