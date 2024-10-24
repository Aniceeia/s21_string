#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(sprintf_d_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  int d = 228;

  int res_1 = s21_sprintf(str, "%10.5d", d);
  int res_1_orig = sprintf(str_orig, "%10.5d", d);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", d);
  int res_2_orig = sprintf(str_orig, "% 10.5d", d);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", d);
  int res_3_orig = sprintf(str_orig, "%3.5d", d);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", d);
  int res_4_orig = sprintf(str_orig, "%d", d);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", d);
  int res_5_orig = sprintf(str_orig, "%0d", d);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", d);
  int res_6_orig = sprintf(str_orig, "%-d", d);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", d);
  int res_7_orig = sprintf(str_orig, "%+d", d);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", d);
  int res_8_orig = sprintf(str_orig, "% d", d);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", d);
  int res_9_orig = sprintf(str_orig, "%5d", d);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%-5d", d);
  int res_10_orig = sprintf(str_orig, "%-5d", d);
  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%+5d", d);
  int res_11_orig = sprintf(str_orig, "%+5d", d);
  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "% 5d", d);
  int res_12_orig = sprintf(str_orig, "% 5d", d);
  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%.5d", d);
  int res_13_orig = sprintf(str_orig, "%.5d", d);
  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_c_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  char A = 'A';

  int res_1 = s21_sprintf(str, "%c", A);
  int res_1_orig = sprintf(str_orig, "%c", A);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  str[0] = '\0';
  str_orig[0] = '\0';
  int res_2 = s21_sprintf(str, "%-c", A);
  int res_2_orig = sprintf(str_orig, "%-c", A);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  str[0] = '\0';
  str_orig[0] = '\0';
  int res_3 = s21_sprintf(str, "%10c", A);
  int res_3_orig = sprintf(str_orig, "%10c", A);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  str[0] = '\0';
  str_orig[0] = '\0';
  int res_4 = s21_sprintf(str, "%-2c", A);
  int res_4_orig = sprintf(str_orig, "%-2c", A);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_s_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  char *A = "Ochko";

  int res_1 = s21_sprintf(str, "%s", A);
  int res_1_orig = sprintf(str_orig, "%s", A);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%-s", A);
  int res_2_orig = sprintf(str_orig, "%-s", A);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%10s", A);
  int res_3_orig = sprintf(str_orig, "%10s", A);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%.5s", A);
  int res_4_orig = sprintf(str_orig, "%.5s", A);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-10s", A);
  int res_5_orig = sprintf(str_orig, "%-10s", A);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_ld_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  long int d = 1504389565748;

  int res_1 = s21_sprintf(str, "%10.5ld", d);
  int res_1_orig = sprintf(str_orig, "%10.5ld", d);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5ld", d);
  int res_2_orig = sprintf(str_orig, "% 10.5ld", d);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5ld", d);
  int res_3_orig = sprintf(str_orig, "%3.5ld", d);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%ld", d);
  int res_4_orig = sprintf(str_orig, "%ld", d);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-ld", d);
  int res_5_orig = sprintf(str_orig, "%-ld", d);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%+ld", d);
  int res_6_orig = sprintf(str_orig, "%+ld", d);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "% ld", d);
  int res_7_orig = sprintf(str_orig, "% ld", d);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%5ld", d);
  int res_8_orig = sprintf(str_orig, "%5ld", d);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5ld", d);
  int res_9_orig = sprintf(str_orig, "%-5ld", d);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%+5ld", d);
  int res_10_orig = sprintf(str_orig, "%+5ld", d);
  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "% 5ld", d);
  int res_11_orig = sprintf(str_orig, "% 5ld", d);
  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%.5ld", d);
  int res_12_orig = sprintf(str_orig, "%.5ld", d);
  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(sprintf_u_test) {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  unsigned int u = 228;

  int res_1 = s21_sprintf(str, "%10.5u", u);
  int res_1_orig = sprintf(str_orig, "%10.5u", u);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%-10.5u", u);
  int res_2_orig = sprintf(str_orig, "%-10.5u", u);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", u);
  int res_3_orig = sprintf(str_orig, "%3.5u", u);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%u", u);
  int res_4_orig = sprintf(str_orig, "%u", u);
  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%u", u);
  int res_5_orig = sprintf(str_orig, "%u", u);
  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%5u", u);
  int res_6_orig = sprintf(str_orig, "%5u", u);
  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%-5u", u);
  int res_7_orig = sprintf(str_orig, "%-5u", u);
  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%10.5u", u);
  int res_8_orig = sprintf(str_orig, "%10.5u", u);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%.5u", u);
  int res_9_orig = sprintf(str_orig, "%.5u", u);
  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_proc) {
  char buf1[100];
  char buf2[100];
  sprintf(buf1, "%%");
  s21_sprintf(buf2, "%%");
  ck_assert_str_eq(buf1, buf2);

  // Простые тесты
}
END_TEST

START_TEST(test_simple) {
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf8[100];
  char buf9[100];
  char buf10[100];
  char buf11[100];

  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  char buf8_[100];
  char buf9_[100];
  char buf10_[100];
  char buf11_[100];

  sprintf(buf2, "%g", 0.000000001);
  s21_sprintf(buf2_, "%g", 0.000000001);
  sprintf(buf3, "%G", 0.000000001);
  s21_sprintf(buf3_, "%G", 0.000000001);
  sprintf(buf4, "%e", 123456789.123456789);
  s21_sprintf(buf4_, "%e", 123456789.123456789);
  sprintf(buf5, "%E", 123456789.123456789);
  s21_sprintf(buf5_, "%E", 123456789.123456789);
  sprintf(buf6, "%x", 0xabcdef);
  s21_sprintf(buf6_, "%x", 0xabcdef);
  sprintf(buf7, "%X", 0xABCDEF);
  s21_sprintf(buf7_, "%X", 0xABCDEF);
  sprintf(buf8, "%x", 0xABCDEF);
  s21_sprintf(buf8_, "%x", 0xABCDEF);
  sprintf(buf9, "%X", 0xabcdef);
  s21_sprintf(buf9_, "%X", 0xabcdef);
  sprintf(buf10, "%o", 20);
  s21_sprintf(buf10_, "%o", 20);

  double number = 123456789.123456789;
  void *ptr_1 = &number;
  void *ptr_2 = &number;
  sprintf(buf11, "%p", ptr_1);
  s21_sprintf(buf11_, "%p", ptr_2);

  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
  ck_assert_str_eq(buf8, buf8_);
  ck_assert_str_eq(buf9, buf9_);
  ck_assert_str_eq(buf10, buf10_);
  ck_assert_str_eq(buf11, buf11_);
}
END_TEST

START_TEST(test_complex_e) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  sprintf(buf1, "%*.e", 10, 123456789.123456789);
  s21_sprintf(buf1_, "%*.e", 10, 123456789.123456789);
  sprintf(buf2, "%.*e", 5, 123456789.123456789);
  s21_sprintf(buf2_, "%.*e", 5, 123456789.123456789);
  sprintf(buf3, "%*.*e", 10, 5, 123456789.123456789);
  s21_sprintf(buf3_, "%*.*e", 10, 5, 123456789.123456789);
  sprintf(buf4, "%020e", 123456789.123456789);
  s21_sprintf(buf4_, "%020e", 123456789.123456789);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
}
END_TEST

START_TEST(test_complex_E) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  sprintf(buf1, "%*.E", 10, 123456789.123456789);
  s21_sprintf(buf1_, "%*.E", 10, 123456789.123456789);
  sprintf(buf2, "%.*E", 5, 123456789.123456789);
  s21_sprintf(buf2_, "%.*E", 5, 123456789.123456789);
  sprintf(buf3, "%*.*E", 10, 5, 123456789.123456789);
  s21_sprintf(buf3_, "%*.*E", 10, 5, 123456789.123456789);
  sprintf(buf4, "%020E", 123456789.123456789);
  s21_sprintf(buf4_, "%020E", 123456789.123456789);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
}
END_TEST

START_TEST(test_complex_x) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  sprintf(buf1, "%*.x", 10, 0xabcdef);
  s21_sprintf(buf1_, "%*.x", 10, 0xabcdef);
  sprintf(buf2, "%.*x", 5, 0xabcdef);
  s21_sprintf(buf2_, "%.*x", 5, 0xabcdef);
  sprintf(buf3, "%*.*x", 10, 5, 0xabcdef);
  s21_sprintf(buf3_, "%*.*x", 10, 5, 0xabcdef);
  sprintf(buf4, "%020x", 0xabcdef);
  s21_sprintf(buf4_, "%020x", 0xabcdef);
  sprintf(buf5, "%#x", 0xabcdef);
  s21_sprintf(buf5_, "%#x", 0xabcdef);
  sprintf(buf6, "%#x", 0XABCDEF);
  s21_sprintf(buf6_, "%#x", 0XABCDEF);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
}
END_TEST

START_TEST(test_complex_X) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  sprintf(buf1, "%*.X", 10, 0XABCDEF);
  s21_sprintf(buf1_, "%*.X", 10, 0XABCDEF);
  sprintf(buf2, "%.*X", 5, 0XABCDEF);
  s21_sprintf(buf2_, "%.*X", 5, 0XABCDEF);
  sprintf(buf3, "%*.*X", 10, 5, 0XABCDEF);
  s21_sprintf(buf3_, "%*.*X", 10, 5, 0XABCDEF);
  sprintf(buf4, "%020X", 0XABCDEF);
  s21_sprintf(buf4_, "%020X", 0XABCDEF);
  sprintf(buf5, "%#X", 0XABCDEF);
  s21_sprintf(buf5_, "%#X", 0XABCDEF);
  sprintf(buf6, "%#X", 0xabcdef);
  s21_sprintf(buf6_, "%#X", 0xabcdef);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
}
END_TEST

START_TEST(test_complex_o) {
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  sprintf(buf1, "%*.o", 10, 20);
  s21_sprintf(buf1_, "%*.o", 10, 20);
  sprintf(buf2, "%.*o", 5, 20);
  s21_sprintf(buf2_, "%.*o", 5, 20);
  sprintf(buf3, "%*.*o", 10, 5, 20);
  s21_sprintf(buf3_, "%*.*o", 10, 5, 20);
  sprintf(buf4, "%020o", 20);
  s21_sprintf(buf4_, "%020o", 20);
  sprintf(buf5, "%#o", 20);
  s21_sprintf(buf5_, "%#o", 20);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
}
END_TEST

START_TEST(test_anomal_large_int) {
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%ld", 1234567890000001);
  s21_sprintf(buf1_, "%ld", 1234567890000001);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

START_TEST(test_precision) {
  double number = 127.9991;
  char buf1[100];
  char buf2[100];

  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf1_[100];
  char buf2_[100];

  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  sprintf(buf1, "%.*f", 3, number);
  s21_sprintf(buf1_, "%.*f", 3, number);
  sprintf(buf2, "%.*g", 3, number);
  s21_sprintf(buf2_, "%.*g", 3, number);
  sprintf(buf4, "%.*f", 0, number);
  s21_sprintf(buf4_, "%.*f", 0, number);

  number = 127.1991;
  sprintf(buf5, "%.*f", 0, number);
  s21_sprintf(buf5_, "%.*f", 0, number);
  sprintf(buf6, "%.*e", 3, number);
  s21_sprintf(buf6_, "%.*e", 3, number);
  sprintf(buf7, "%.*e", 0, number);
  s21_sprintf(buf7_, "%.*e", 0, number);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);

  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
}
END_TEST

START_TEST(test_large_int) {
  long int number = 1234567890000000001LL;
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%ld", number);
  s21_sprintf(buf1_, "%ld", number);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

START_TEST(test_hash_e) {
  double number = 0.8;
  char buf1[100];
  char buf1_[100];
  char buf2[100];
  char buf2_[100];
  sprintf(buf1, "%#e", number);
  s21_sprintf(buf1_, "%#e", number);
  sprintf(buf2, "%#e", 0.0);
  s21_sprintf(buf2_, "%#e", 0.0);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_zero_padding) {
  double number = 0.8;
  char buf1[100];
  char buf2[100];
  char buf3[100];
  char buf4[100];
  char buf5[100];
  char buf6[100];
  char buf7[100];
  char buf8[100];
  char buf9[100];
  char buf1_[100];
  char buf2_[100];
  char buf3_[100];
  char buf4_[100];
  char buf5_[100];
  char buf6_[100];
  char buf7_[100];
  char buf8_[100];
  char buf9_[100];
  sprintf(buf1, "%08e", number);
  s21_sprintf(buf1_, "%08e", number);
  sprintf(buf2, "%08f", number);
  s21_sprintf(buf2_, "%08f", number);
  sprintf(buf3, "%08f", 9.1);
  s21_sprintf(buf3_, "%08f", 9.1);
  sprintf(buf4, "%08g", number);
  s21_sprintf(buf4_, "%08g", number);
  sprintf(buf5, "%023g", number);
  s21_sprintf(buf5_, "%023g", number);
  sprintf(buf6, "%08G", number);
  s21_sprintf(buf6_, "%08G", number);
  sprintf(buf7, "%023G", number);
  s21_sprintf(buf7_, "%023G", number);
  sprintf(buf8, "%08d", 10);
  s21_sprintf(buf8_, "%08d", 10);
  sprintf(buf9, "%023d", 10);
  s21_sprintf(buf9_, "%023d", 10);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
  ck_assert_str_eq(buf3, buf3_);
  ck_assert_str_eq(buf4, buf4_);
  ck_assert_str_eq(buf5, buf5_);
  ck_assert_str_eq(buf6, buf6_);
  ck_assert_str_eq(buf7, buf7_);
  ck_assert_str_eq(buf8, buf8_);
  ck_assert_str_eq(buf9, buf9_);
}
END_TEST

START_TEST(test_mixed_ld) {
  long int number = 1234567890000000001LL;
  char buf1[100];
  char buf2[100];
  char buf1_[100];
  char buf2_[100];
  sprintf(buf1, "%*.*ld", 5, 8, number);
  s21_sprintf(buf1_, "%*.*ld", 5, 8, number);
  sprintf(buf2, "%*.*ld", 5, 10, number);
  s21_sprintf(buf2_, "%*.*ld", 5, 10, number);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_mixed_f) {
  double num = 12000.9;
  char buf1[100];
  char buf2[100];
  char buf1_[100];
  char buf2_[100];
  sprintf(buf1, "%0#*.*f", 10, 1, num);
  s21_sprintf(buf1_, "%0#*.*f", 10, 1, num);
  sprintf(buf2, "%0#*.*f", 10, 14, num);
  s21_sprintf(buf2_, "%0#*.*f", 10, 14, num);
  ck_assert_str_eq(buf1, buf1_);
  ck_assert_str_eq(buf2, buf2_);
}
END_TEST

START_TEST(test_mixed_e) {
  double num = 12000.9;
  char buf1[100];
  char buf1_[100];
  sprintf(buf1, "%0#*.*e", 10, 14, num);
  s21_sprintf(buf1_, "%0#*.*e", 10, 14, num);
  ck_assert_str_eq(buf1, buf1_);
}
END_TEST

Suite *sprintf_suite() {
  Suite *s = suite_create("sprintf_suite");
  TCase *core = tcase_create("sprintf_suite");

  tcase_add_test(core, sprintf_d_test);
  tcase_add_test(core, sprintf_c_test);
  tcase_add_test(core, sprintf_s_test);
  tcase_add_test(core, sprintf_ld_test);
  tcase_add_test(core, sprintf_u_test);
  tcase_add_test(core, test_proc);
  tcase_add_test(core, test_simple);
  tcase_add_test(core, test_complex_e);
  tcase_add_test(core, test_complex_E);
  tcase_add_test(core, test_complex_x);
  tcase_add_test(core, test_complex_X);
  tcase_add_test(core, test_complex_o);
  tcase_add_test(core, test_anomal_large_int);
  tcase_add_test(core, test_precision);
  tcase_add_test(core, test_large_int);
  tcase_add_test(core, test_hash_e);
  tcase_add_test(core, test_zero_padding);
  tcase_add_test(core, test_mixed_ld);
  tcase_add_test(core, test_mixed_f);
  tcase_add_test(core, test_mixed_e);
  suite_add_tcase(s, core);

  return s;
}
