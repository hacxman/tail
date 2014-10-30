#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "usage: %s BYTES file\n", argv[0]);
    return EXIT_FAILURE;
  }

  long len = atol(argv[1]);
  FILE *f = fopen(argv[2], "r");

  if (fseek(f, -len, SEEK_END)) {
    perror("fseek pojebalo");
    return EXIT_FAILURE;
  }

  char * mem = malloc(len);
  fread(mem, len, 1, f);
  fwrite(mem, len, 1, stdout);

  fclose(f);
  free(mem);
  return EXIT_SUCCESS;
}
