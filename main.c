#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "random.h"

char** initMap(int rows, int cols, int* player, int* cars, char* carState) {
  int i, j = 0;

  /* Make a double pointer that will be our 2D Arrray*/
  char** map = (char**)malloc(cols * sizeof(char*));

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

  /* Place cars */
  for(i = 0; i < cols - 2; i++) {
    if(i % 2 == 0) {
      map[i][cars[i]] = carState[randomUCP(0, 1)];
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

  map[player[0]][player[1]] = 'P';
  map[cols-2][rows-2] = 'G';

  return map;
}

int* initCars(int rows, int cols) {
  int i = 0;
  
  int* cars = (int*)malloc(cols * sizeof(int));

  for(i = 0; i < cols - 2; i++) {
    if(i % 2 == 0) {
      cars[i] = randomUCP(1, rows - 2);
    }
  }

  return cars;
}

char* initCarState() {
  char* carState = (char*)malloc(2 * sizeof(char));
  carState[0] = '<';
  carState[1] = '>';

  return carState;
}

int* initPlayer() {
  /* Make player 1D array to store x and y co-ordinates */
  int* player = (int*)malloc(2 * sizeof(int));

  player[0] = 1; 
  player[1] = 1;

  initRandom();

  return player;
}

void refresh() {
  system("cls");
}

int main(int argc, char* argv[]) {
  int i = 0, j = 0;

  /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[2]) + 2;
  int cols = atoi(argv[1]) + 2;

  int* player = initPlayer();
  int* cars = initCars(rows, cols);
  char* carState = initCarState();
  char** map = initMap(rows, cols, player, cars, carState);

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

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < cols; i++) {
    free(map[i]);
  }
  
  free(player);
  free(cars);
  free(carState);
  free(map);

  return 0;
}