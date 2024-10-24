#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char str_strtok2[] = "one/two/three(four)five";
  char str_strtok3[] = " ";
  char str_strtok4[] = " ";
  char str_strtok5[] = "GqwerGqwer";
  char str_strtok6[] = "GqwerGqwer";

  char delim1[] = "/()";
  char delim2[] = "/()";
  char delim3[] = " ";
  char delim4[] = "G";

  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);

  char *aish = s21_strtok(str_strtok3, delim3);
  char *orig_aish = strtok(str_strtok4, delim3);
  char *aish1 = s21_strtok(str_strtok5, delim4);
  char *orig_aish1 = strtok(str_strtok6, delim4);

  ck_assert_ptr_eq(aish, orig_aish);
  ck_assert_str_eq(aish1, orig_aish1);

  while (my_strtok != NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(NULL, delim1);
    origin_strtok = strtok(NULL, delim2);
  }
}
END_TEST

Suite *strtok_suite() {
  Suite *s = suite_create("strtok_suite");
  TCase *core = tcase_create("strtok_suite");

  tcase_add_test(core, strtok_test);
  suite_add_tcase(s, core);

  return s;
}