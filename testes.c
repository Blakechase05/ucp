#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[]) {
  int i, j, rows, cols;

  int** intMap;

  /* File pointer to <fileName>.txt */
  FILE* fp = fopen(argv[1], "r");

  /* Check there's an input for fp */
  if(fp != NULL) {
    /* Check for errors when doing anything with the file */
    if(ferror(fp)) {
      perror("Error reading from text file.");
    }
    
    fscanf(fp, "%d %d", &rows, &cols);
    /* Add 2 slots onto rows and cols for the border */
    rows += 2;
    cols += 2;

    intMap = initIntMap(fp, rows, cols, intMap);

  } else {
    perror("Cannot open file");
  }

  for (i = 1; i < rows - 1; i++) {
    for (j = 1; j < cols - 1; j++) {
      printf("%d", intMap[i][j]);
    }
  }

  return 0;
}