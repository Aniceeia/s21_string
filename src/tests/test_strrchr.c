#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strrchr_test) {
  char t_1[] = "0163456769";
  char t_2[] = ";;;;;;H%%//#HH";
  char t_3[] = " /";

  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, '6'),
                    (unsigned long)strrchr(t_1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, ' '),
                    (unsigned long)strrchr(t_1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_1, '6'),
                    (unsigned long)strrchr(t_1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, 'H'),
                    (unsigned long)strrchr(t_2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, '$'),
                    (unsigned long)strrchr(t_2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_2, ';'),
                    (unsigned long)strrchr(t_2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(t_3, ' '),
                    (unsigned long)strrchr(t_3, ' '));
  ck_assert_str_eq(s21_strrchr(t_2, '\0'), strrchr(t_2, '\0'));
}
END_TEST

Suite *strrchr_suite() {
  Suite *s = suite_create("strrchr_suite");
  TCase *core = tcase_create("strrchr_suite");

  tcase_add_test(core, strrchr_test);
  suite_add_tcase(s, core);

  return s;
}