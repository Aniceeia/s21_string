#include "tests.h"

START_TEST(s21_to_upper_test) {
  char str_1[] = "LoL The WoRld!";
  char str_2[] = "If_the_Bears_were\t\nbees";  // спецсимволы
  char str_3[] = "";                           // пустая строка
  char str_4[] = "q";  // строка с 1 символом
  char str_5[] = "\t \n";
  char *str_6 = NULL;
  char *res = NULL;
  ck_assert_str_eq(res = s21_to_upper(str_1), "LOL THE WORLD!");
  free(res);
  ck_assert_str_eq(res = s21_to_upper(str_2), "IF_THE_BEARS_WERE\t\nBEES");
  free(res);
  ck_assert_str_eq(res = s21_to_upper(str_3), str_3);
  free(res);
  ck_assert_str_eq(res = s21_to_upper(str_4), "Q");
  free(res);
  ck_assert_str_eq(res = s21_to_upper(str_5), str_5);
  free(res);
  ck_assert_ptr_eq(res = s21_to_upper(str_6), NULL);
}

START_TEST(s21_to_lower_test) {
  char str_1[] = "LoL ThE WoRld!";
  char str_2[] = "IF_the_BeARs_WERE\t\nbeeS";  // спецсимволы
  char str_3[] = "";                           // пустая строка
  char str_4[] = "q";  // строка с 1 символом
  char str_5[] = "\t \n";
  char *str_6 = NULL;
  char *res = NULL;
  ck_assert_str_eq(res = s21_to_lower(str_1), "lol the world!");
  free(res);
  ck_assert_str_eq(res = s21_to_lower(str_2), "if_the_bears_were\t\nbees");
  free(res);
  ck_assert_str_eq(res = s21_to_lower(str_3), str_3);
  free(res);
  ck_assert_str_eq(res = s21_to_lower(str_4), "q");
  free(res);
  ck_assert_str_eq(res = s21_to_lower(str_5), str_5);
  free(res);
  ck_assert_ptr_eq(res = s21_to_lower(str_6), NULL);
}

START_TEST(s21_insert_test) {
  char str_1[] = "LoL ThE WoRld!";
  char str_2[] = "IF_the_BeARs_WERE\t\nbeeS";  // спецсимволы
  char str_3[] = "AGAIN\n!";
  char str_4[] = "\0";
  char *res = NULL;
  ck_assert_str_eq(res = s21_insert(str_1, str_3, 4), "LoL AGAIN\n!ThE WoRld!");
  free(res);
  ck_assert_str_eq(res = s21_insert(str_3, str_2, 5),
                   "AGAINIF_the_BeARs_WERE\t\nbeeS\n!");
  free(res);
  ck_assert_str_eq(res = s21_insert(str_3, str_4, 1), str_3);
  free(res);
  ck_assert_str_eq(res = s21_insert(str_2, str_4, 0), str_2);
  free(res);
  ck_assert_ptr_eq(res = s21_insert(str_3, str_2, 8), NULL);
  ck_assert_ptr_eq(res = s21_insert(NULL, str_2, 8), NULL);
  ck_assert_ptr_eq(res = s21_insert(NULL, NULL, 8), NULL);
}

START_TEST(s21_trim_test) {
  char str_1[] = "LoL ThE WoRld!";
  char str_2[] = "\0";
  char *res = NULL;
  ck_assert_str_eq(res = s21_trim(str_1, "Lod!"), " ThE WoRl");
  free(res);
  ck_assert_str_eq(res = s21_trim(str_1, NULL), str_1);
  free(res);
  ck_assert_ptr_null(res = s21_trim(NULL, NULL));
  ck_assert_ptr_null(res = s21_trim(NULL, "123"));
  ck_assert_str_eq(res = s21_trim(str_2, NULL), str_2);
  free(res);
}

Suite *sharp_suite() {
  Suite *s = suite_create("sharp_suite");
  TCase *core = tcase_create("sharp_suite");

  tcase_add_test(core, s21_to_upper_test);
  tcase_add_test(core, s21_to_lower_test);
  tcase_add_test(core, s21_insert_test);
  tcase_add_test(core, s21_trim_test);
  suite_add_tcase(s, core);

  return s;
}
