#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strlen_test) {
  char t_1[] = "12312\0";
  char t_2[] = "//\0\n\0";
  char t_3[] = "dfdfd11\0";
  char t_4[] = "\0";
  char t_5[] = "\0";
  char t_6[] = "'f'f1213/v/f/////\0";
  char t_7[] = "";
  char t_8[] = " ";
  char t_9[] = "@#$%6&*()\n\t";

  ck_assert_int_eq(s21_strlen(t_1), strlen(t_1));
  ck_assert_int_eq(s21_strlen(t_2), strlen(t_2));
  ck_assert_int_eq(s21_strlen(t_3), strlen(t_3));
  ck_assert_int_eq(s21_strlen(t_4), strlen(t_4));
  ck_assert_int_eq(s21_strlen(t_5), strlen(t_5));
  ck_assert_int_eq(s21_strlen(t_6), strlen(t_6));
  ck_assert_int_eq(s21_strlen(t_7), strlen(t_7));
  ck_assert_int_eq(s21_strlen(t_8), strlen(t_8));
  ck_assert_int_eq(s21_strlen(t_9), strlen(t_9));
}
END_TEST

Suite *strlen_suite() {
  Suite *s = suite_create("strlen_suite");
  TCase *core = tcase_create("strlen_suite");

  tcase_add_test(core, strlen_test);
  suite_add_tcase(s, core);

  return s;
}