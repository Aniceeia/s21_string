#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strncat_test) {
  char t_1[4] = "<<<\0";
  char t_2[2] = "5\0";
  char t_3[2] = "5\0";
  char t_4[] = "\0";

  ck_assert_str_eq(s21_strncat(t_1, t_2, 1), "<<<5\0");
  ck_assert_str_eq(s21_strncat(t_3, t_4, 0), strncat(t_2, t_4, 0));
}
END_TEST

Suite *strncat_suite() {
  Suite *s = suite_create("strncat_suite");
  TCase *core = tcase_create("strncat_suite");

  tcase_add_test(core, strncat_test);
  suite_add_tcase(s, core);

  return s;
}