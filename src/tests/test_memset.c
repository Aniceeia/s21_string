#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memset_test) {
  unsigned char t_1[10] = "1234567890";
  unsigned char t_2[10] = "Hello";

  ck_assert_uint_eq((unsigned long)s21_memset(t_1, '6', 10),
                    (unsigned long)memset(t_1, '6', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(t_1, '2', 10),
                    (unsigned long)memset(t_1, '2', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(t_1, '0', 1),
                    (unsigned long)memset(t_1, '0', 1));
  ck_assert_uint_eq((unsigned long)s21_memset(t_1, '/', 6),
                    (unsigned long)memset(t_1, '/', 6));
  ck_assert_uint_eq((unsigned long)s21_memset(t_2, '4', 4),
                    (unsigned long)memset(t_2, '4', 4));
}
END_TEST

Suite *memset_suite() {
  Suite *s = suite_create("memset_suite");
  TCase *core = tcase_create("memset_suite");

  tcase_add_test(core, memset_test);
  suite_add_tcase(s, core);

  return s;
}