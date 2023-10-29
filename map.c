#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int** initIntMap(FILE* fp, int rows, int cols, int** intMap) {
  int i, j;
  
  /* Malloc the 2D array to store our integers from the file */
  intMap = (int**)malloc(rows * sizeof(int*));
  for (i = 0; i < rows; i++) {
    intMap[i] = (int*)malloc(cols * sizeof(int));
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      intMap[i][j] = 5;
    }
  }

  for (i = 1; i < rows - 1; i++) {
    for (j = 1; j < cols - 1; j++) {
      fscanf(fp, "%d", &intMap[i][j]);
    }
  }

  fclose(fp);

  return intMap;
}