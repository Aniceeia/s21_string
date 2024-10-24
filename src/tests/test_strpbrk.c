#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strpbrk_test) {
  char t_1[] = "01234ffffff";
  char t_2[] = "7773";
  char *str = "Hello, world";
  char *empty = "";

  ck_assert_str_eq(s21_strpbrk(t_1, t_2), "34ffffff");
  ck_assert_str_eq(s21_strpbrk(t_1, t_2), strpbrk(t_1, t_2));

  ck_assert_ptr_eq(s21_strpbrk(str, empty), NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

Suite *strpbrk_suite() {
  Suite *s = suite_create("strpbrk_suite");
  TCase *core = tcase_create("strpbrk_suite");

  tcase_add_test(core, strpbrk_test);
  suite_add_tcase(s, core);

  return s;
}