#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *memchr_suite();
Suite *memcmp_suite();
Suite *memcpy_suite();
Suite *memset_suite();
Suite *strncat_suite();
Suite *strchr_suite();
Suite *strncmp_suite();
Suite *strncpy_suite();
Suite *strcspn_suite();
Suite *strerror_suite();
Suite *strlen_suite();
Suite *strpbrk_suite();
Suite *strrchr_suite();
Suite *strstr_suite();
Suite *strtok_suite();
Suite *sharp_suite();

Suite *sprintf_suite();

#endif
