#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcpy_test) {
  char t_1[] = "123456";
  char t_2[10] = {0};
  char t_3[] = "111 ";
  char t_4[8] = " 111";
  char t_5[] = "qwerty";
  char t_6[] = "\0";

  ck_assert_str_eq(s21_memcpy(t_2, t_1, 6), memcpy(t_2, t_1, 6));
  ck_assert_str_eq(s21_memcpy(t_2, t_4, 6), memcpy(t_2, t_4, 6));
  ck_assert_str_eq(s21_memcpy(t_2, t_3, 4), memcpy(t_2, t_3, 4));
  ck_assert_str_eq(s21_memcpy(t_2, t_5, 6), memcpy(t_2, t_5, 6));
  ck_assert_str_eq(s21_memcpy(t_2, t_6, 1), memcpy(t_2, t_6, 1));
}
END_TEST

Suite *memcpy_suite() {
  Suite *s = suite_create("memcpy_suite");
  TCase *core = tcase_create("memcpy_suite");

  tcase_add_test(core, memcpy_test);
  suite_add_tcase(s, core);

  return s;
}