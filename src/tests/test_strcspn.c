#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strcspn_test) {
  char t_1[] = "12314241";
  char t_2[] = "fffff";
  char t_3[] = "//\0\n";
  char t_4[] = "goga";
  char t_5[] = "22222111111111";
  char t_6[] = "22222111111111";

  ck_assert_uint_eq(s21_strcspn(t_1, t_2), strcspn(t_1, t_2));
  ck_assert_uint_eq(s21_strcspn(t_2, t_3), strcspn(t_2, t_3));
  ck_assert_uint_eq(s21_strcspn(t_4, t_3), strcspn(t_4, t_3));
  ck_assert_uint_eq(s21_strcspn(t_5, t_4), strcspn(t_5, t_4));
  ck_assert_uint_eq(s21_strcspn(t_5, t_6), strcspn(t_5, t_6));
}
END_TEST

Suite *strcspn_suite() {
  Suite *s = suite_create("strcspn_suite");
  TCase *core = tcase_create("strcspn_suite");

  tcase_add_test(core, strcspn_test);
  suite_add_tcase(s, core);

  return s;
}
