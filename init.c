#include <stdio.h>
#include <stdlib.h>

#include "random.h"
#include "newSleep.h"

char** initMap(int rows, int cols, int* player, int* cars, char* carState) {
  int i, j = 0;

  /* Make a double pointer that will be our 2D Arrray*/
  char** map = (char**)malloc(cols * sizeof(char*));

  for (i = 0; i < cols; i++) {
    map[i] = (char*)malloc(rows * sizeof(char));
  }

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      if(i % 2 == 0) {
        map[i][j] = '.';
      }
    }
  }

  for(i = 0; i < cols - 2; i++) {
      map[i][cars[i]] = carState[i];
  }

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      if(i % 2 == 1) {
        map[i][j] = ' ';
      }
    }
  }

  /* Side borders */
  for (i = 0; i < rows; i++) {
    map[0][i] = '*';
    map[cols-1][i] = '*';
  }

  /* Top and bottom borders */
  for (i = 0; i < cols; i++) {
    map[i][0] = '*';
    map[i][rows-1] = '*';
  }

  /* Place player */
  map[player[0]][player[1]] = 'P';
  
  /* Place goal */
  map[cols-2][rows-2] = 'G';

  /* First map print */
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  return map;
}

/* Initialise where the cars will sit */
int* initCars(int rows, int cols) {
  int i = 0;
  
  int* cars = (int*)malloc(cols * sizeof(int));

  for(i = 0; i < cols - 2; i++) {
    cars[i] = randomUCP(1, rows - 2);
  }

  return cars;
}

/* Initialise what direction the cars will be */
char* initCarState(int cols) {
  int i = 0;
  
  char* state = (char*)malloc(2 * sizeof(char));
  char* carStates = (char*)malloc(cols * sizeof(char));
  
  state[0] = '<';
  state[1] = '>';

  /* Place cars */
  for(i = 0; i < cols; i++) {
      carStates[i] = state[randomUCP(0, 1)];
  }

  return carStates;
}

/* Initialise the player */
int* initPlayer() {
  /* Make player 1D array to store x and y co-ordinates */
  int* player = (int*)malloc(2 * sizeof(int));

  player[0] = 1; 
  player[1] = 1;

  initRandom();

  return player;
}