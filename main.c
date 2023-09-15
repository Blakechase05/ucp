#include <stdio.h>
#include <stdlib.h>

#include "main.h"

char** init(int rows, int cols) {
  int i, j = 0;

  /* Make a double pointer that will be our 2D Arrray*/
  char **map;

  map = (char**)malloc(cols * sizeof(char*));

  for(i = 0; i < cols; i++) {
    map[i] = (char*)malloc(rows * sizeof(char));
  }


  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      if(i % 2 == 0) {
        map[i][j] = '.';
      } else {
        map[i][j] = ' ';
      }
    }
  }

  for (i = 0; i < rows; i++) {
    map[0][i] = '*';
    map[cols-1][i] = '*';
  }

  for (i = 0; i < cols; i++) {
    map[i][0] = '*';
    map[i][rows-1] = '*';
  }

  map[1][1] = 'P';
  map[cols-2][rows-2] = 'G';

  system("cls");

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf(" %c", map[i][j]);
    }
    printf("\n");
  }

  return map;
}

int main(int argc, char* argv[]) {
  int i, j = 0;

  /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[1]) + 2;
  int cols = atoi(argv[2]) + 2;

  if(cols % 2 == 0) {
    printf("Even number of columns, cya l8r allig8r");
    return 1; 
  }

  if(rows - 2 < 3) {
    printf("The number of rows can't be less than 3, exiting program");
    return 1;
  }

  if(cols - 2 < 5) {
    printf("The number of columns can't be less than 5, exiting program");
    return 1;
  }

  char** m = init(rows, cols);

  for (i = 0; i < cols; i++) {
    free(m[i]);
  }
  
  free(m);

  return 0;
}