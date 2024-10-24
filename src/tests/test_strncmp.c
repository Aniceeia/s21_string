#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strncmp_test) {
  char t_1[] = "Hello World 1";
  char t_2[] = "Hella Worda 2";

  ck_assert_int_eq(s21_strncmp(t_1, t_2, 13) < 0, strncmp(t_1, t_2, 13) < 0);
  ck_assert_int_eq(s21_strncmp(t_1, t_2, 4) == 0, strncmp(t_1, t_2, 4) == 0);
}
END_TEST

Suite *strncmp_suite() {
  Suite *s = suite_create("strncmp_suite");
  TCase *core = tcase_create("strncmp_suite");

  tcase_add_test(core, strncmp_test);
  suite_add_tcase(s, core);

  return s;
}