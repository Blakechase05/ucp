#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void init() {
  system("clear");

}

int main(int argc, char* argv[]) {
  int i, j = 0;

  /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[1]) + 2;
  int cols = atoi(argv[2]) + 2;
  
  /* Make a double pointer that will be our 2D Arrray*/
  char **map;

  map = (char**)malloc(cols * sizeof(char*));

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

  for(i = 0; i < cols; i++) {
    map[i] = (char*)malloc(rows * sizeof(char));
  }

  init();

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

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf(" %c", map[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < cols; i++) {
    free(map[i]);
  }
  
  free(map);

  return 0;
}