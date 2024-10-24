#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcmp_test) {
  char t_1[] = "!@#123321312!#@";
  char t_2[] = "Helli-ku";
  char t_3[] = "MEAOU";
  char t_4[] = "\n\t\0";
  char t_5[] = "\0";

  ck_assert_uint_eq(s21_memcmp(t_1, t_2, 8) < 0, memcmp(t_1, t_2, 8) < 0);
  ck_assert_uint_eq(s21_memcmp(t_2, t_3, 5) < 0, memcmp(t_2, t_3, 5) < 0);
  ck_assert_uint_eq(s21_memcmp(t_3, t_4, 3) < 0, memcmp(t_3, t_4, 3) < 0);
  ck_assert_uint_eq(s21_memcmp(t_4, t_5, 1) < 0, memcmp(t_4, t_5, 1) < 0);
  ck_assert_uint_eq(s21_memcmp(t_1, t_1, 14) < 0, memcmp(t_1, t_1, 14) < 0);
  ck_assert_uint_eq(s21_memcmp(t_1, t_1, 10) < 0, memcmp(t_1, t_1, 10) < 0);
  ck_assert_uint_eq(s21_memcmp(t_1, t_2, 5) < 0, memcmp(t_1, t_2, 5) < 0);
}
END_TEST

Suite *memcmp_suite() {
  Suite *s = suite_create("memcmp_suite");
  TCase *core = tcase_create("memcmp_suite");

  tcase_add_test(core, memcmp_test);
  suite_add_tcase(s, core);

  return s;
}
