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
  int i = 0;

  /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[1]) + 2;
  int cols = atoi(argv[2]) + 2;

  int* cars;


  cars = (int*)malloc(cols * sizeof(int));


  for(i = 0; i < cols; i++) {
    cars[i] = 1;
  }

  int size = sizeof(cars) / sizeof(cars[0]);
  printf("%d\n", size);

  for(i = 0; i < size; i++) {
    printf("%d\n", cars[i]);
  }

  free(cars);

  return 0;
} 