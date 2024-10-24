#include <stdio.h>

#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *all_cases[] = {memchr_suite(),   memcmp_suite(),  memcpy_suite(),
                        memset_suite(),   strncat_suite(), strchr_suite(),
                        strncmp_suite(),  strncpy_suite(), strcspn_suite(),
                        strerror_suite(), strlen_suite(),  strpbrk_suite(),
                        strrchr_suite(),  strstr_suite(),  strtok_suite(),
                        sprintf_suite(),  sharp_suite(),   NULL};

  for (Suite **curr_suite = all_cases; *curr_suite != NULL; curr_suite++) {
    printf("\n");
    SRunner *sr = srunner_create(*curr_suite);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed = srunner_ntests_failed(sr) + failed;
    srunner_free(sr);
  }

  printf("\n");

  return failed;
}
