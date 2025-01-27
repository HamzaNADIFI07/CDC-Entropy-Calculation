#include <stdio.h>

#include "tests.h"
#include "../lib/entropy.h"

MU_TESTS_INIT

static int test_entropy_occurrences() {
  FILE *input = fopen("test1", "r");
  int counts_bak[257], *counts;
  int i;

  counts_bak[0]=0;
  counts = &counts_bak[1];
  for (i = 0; i < 256; i++) {
    counts[i] = 0;
  }

  count_occurrences(input, counts);

  mu_assert_eq("counts", counts['a'], 5);
  mu_assert_eq("counts", counts['b'], 3);
  mu_assert_eq("counts", counts['c'], 1);
  mu_assert_eq("counts", counts['d'], 0);

  /* Check that the previous cell of counts has not been altered.
     If this test fails, please check what you're doing in count_occurrences
     when reaching the end of the file.
   */
  mu_assert_eq("counts", counts_bak[0], 0);
  
  fclose(input);
  return 0;
}

static int test_entropy_function() {
  /* À COMPLÉTER */
  
  return 0;
}


static int all_tests() {
   mu_run_test(test_entropy_occurrences);
   mu_run_test(test_entropy_function);
   return mu_tests_success;
}
 
int main(int argc, char **argv) {
  int result = all_tests();
  if (result != 0) {
    fprintf(stderr, "TESTS FAILED!\n");
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d (including %d assertions)\n", mu_tests_run, mu_assert_run);
  
  return result != 0;
}
