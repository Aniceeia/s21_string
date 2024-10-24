#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strerror_test) {
  char *orig = NULL;
  char *copy = NULL;
  for (int i = -200; i < 200; i++) {
    orig = strerror(i);
    copy = s21_strerror(i);
    // ck_assert_str_eq(s21_strerror(i), strerror(i));
    ck_assert_str_eq(orig, copy);
  }
  if (copy) free(orig);
}
END_TEST

Suite *strerror_suite() {
  Suite *s = suite_create("strerror_suite");
  TCase *core = tcase_create("strerror_suite");

  tcase_add_test(core, strerror_test);
  suite_add_tcase(s, core);

  return s;
}
