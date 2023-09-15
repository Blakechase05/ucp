#include <stdio.h>
#include <stdlib.h>

#include "main.h"


char** initMap(int rows, int cols) {
  int i, j = 0;

  /* Make a double pointer that will be our 2D Arrray*/
  char** map;

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

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf(" %c", map[i][j]);
    }

    printf("\n");
  }

  return map;
}

int* initCars(int rows, int cols) {
  int i = 0;

  int* cars;
  
  cars = (int*)malloc(cols * sizeof(int));

  for(i = 0; i < 15; i++) {
    cars[i] = 1;
  }

  int n = sizeof(cars);

  printf("%d", n);

  return cars;
}

void refresh() {
  system("cls");
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

  /* char** map = initMap(rows, cols); */
  int* cars = initCars(rows, cols);

  /* for (i = 0; i < cols; i++) {
    free(map[i]);
  } */
  
  /* free(map); */
  free(cars);

  return 0;
}