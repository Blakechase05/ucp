#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  int i, j = 0;

  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  
  int **map;

  map = (int **)malloc(cols * sizeof(int *));
  
  for(i = 0; i < cols; i++) {
    map[i] = (int*)malloc(rows * sizeof(int));
  }

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      map[i][j] = 0;
    }
  }

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf(" %d", map[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < cols; i++) {
    free(map[i]);
  }
  
  free(map);

  return 0;
}

