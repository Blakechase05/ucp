#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  int r = atoi(argv[1]);
  int c = atoi(argv[2]);
  
  int i, j = 0;

  int (*arr)[c] = malloc(sizeof(int[r][c]));

  free(arr);
 
  return 0;
}