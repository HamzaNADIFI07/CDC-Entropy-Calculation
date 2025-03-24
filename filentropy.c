#include<stdio.h>
#include<stdlib.h>

#include "lib/entropy.h"

int main(int argc, char **argv) {

  if (argc <= 1) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }
  FILE *file = fopen(argv[1], "r");
  /* À COMPLÉTER */
  int counts[256];
  for (int i = 0; i < 256; i++) {
    counts[i] = 0;
  }
  count_occurrences(file, counts);
  struct file_stat fi = entropy(counts);
  int res = 100 - ((fi.entropy/8)*100);
  printf("Le fichier fait %d octets et a une entropie de %.2f bits par octet\n", fi.size, fi.entropy);
  printf("Au mieux un codage optimal améliorerait le stockage de ce fichier de %d %%\n", res);


  fclose(file);
  exit(0);
}
