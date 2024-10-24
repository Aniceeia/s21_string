#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memchr_test) {
  char t_1[] = "1234567";
  char t_2[] = "\twqrwert";
  char t_3[] = "Hello!\n";
  char t_4[] = "DigitaWLLich";
  int t_5 = '3';
  int t_6 = '7';
  int t_7 = '\n';
  int t_8 = 'w';
  int t_9 = '0';

  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_5, 8),
                    (unsigned long)memchr(t_1, t_5, 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_2, t_6, 6),
                    (unsigned long)memchr(t_2, t_6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_3, t_7, 1),
                    (unsigned long)memchr(t_3, t_7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_4, t_8, 4),
                    (unsigned long)memchr(t_4, t_8, 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_9, 2),
                    (unsigned long)memchr(t_1, t_9, 2));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_2, t_5, 3),
                    (unsigned long)memchr(t_2, t_5, 3));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_3, t_6, 7),
                    (unsigned long)memchr(t_3, t_6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_4, t_7, 6),
                    (unsigned long)memchr(t_4, t_7, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(t_1, t_8, 8),
                    (unsigned long)memchr(t_1, t_8, 8));
}
END_TEST

Suite *memchr_suite() {
  Suite *s = suite_create("memchr_suite");
  TCase *core = tcase_create("memchr_suite");

  tcase_add_test(core, memchr_test);
  suite_add_tcase(s, core);

  return s;
}