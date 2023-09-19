#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "random.h"
#include "newSleep.h"
#include "terminal.h"

#define FALSE 0
#define TRUE !FALSE

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
  for (i = 0; i < rows; i++) {
    map[0][i] = '*';
    map[cols-1][i] = '*';
  }

  for (i = 0; i < cols; i++) {
    map[i][0] = '*';
    map[i][rows-1] = '*';
  }

  /* Place Player */
  map[player[0]][player[1]] = 'P';
  
  /* Place Goal */
  map[cols-2][rows-2] = 'G';

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  return map;
}

int* initCars(int rows, int cols) {
  int i = 0;
  
  int* cars = (int*)malloc(cols * sizeof(int));

  for(i = 0; i < cols - 2; i++) {
    cars[i] = randomUCP(1, rows - 2);
  }

  return cars;
}

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

int* initPlayer() {
  /* Make player 1D array to store x and y co-ordinates */
  int* player = (int*)malloc(2 * sizeof(int));

  player[0] = 1; 
  player[1] = 1;

  initRandom();

  return player;
}

int* updatePlayer(int rows, int cols, int* player, char** map) {
  char input;

  disableBuffer();
  scanf(" %c", &input);
  enableBuffer();

  if(input == 'w') {
    if(player[0] != 1) {
      player[0] = player[0] - 1;
    }
  } else if (input == 's') {
    if(player[0] != cols - 2) {
      player[0] = player[0] + 1;
    }
  } else if (input == 'a') {
    if(player[1] != 1) {
      player[1] = player[1] - 1;
    }
  } else if (input == 'd') {
    if(player[1] != rows - 2) {
      player[1] = player[1] + 1;
    }
  }
  return player;
}

int* updateCars(int rows, int cols, int* cars, char* carState, char** map) {
  int i = 0;
  
  for (int i = 0; i < cols; i++) {
    if(carState[i] == '<') {
      if(cars[i] == 2) {
        carState[i] = '>';
      }
      
      map[i][cars[i]] = '.';
      cars[i] = cars[i] - 1;
    
    } else if (carState[i] == '>') {
      if(cars[i] == rows - 3) {
        carState[i] = '<';
      }
      
      map[i][cars[i]] = '.';
      cars[i] = cars[i] + 1;
    }
  }

  return cars;
}

char** updateMap(int rows, int cols, int* player, int* cars, char* carState, char** map) {
  int i, j = 0;

  if(player[0] % 2 == 0) {
    map[player[0]][player[1]] = '.';
  }
  if(player[0] % 2 == 1) {
    map[player[0]][player[1]] = ' ';
  }

  updateCars(rows, cols, cars, carState, map);
  updatePlayer(rows, cols, player, map);

  for(i = 0; i < cols - 2; i++) {
    map[i][cars[i]] = carState[i];
  }

  system("clear");

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      if(i % 2 == 1) {
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

  map[player[0]][player[1]] = 'P';
  map[cols-2][rows-2] = 'G';

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  
  printf("Press w to move up\n");
  printf("Press a to move left\n");
  printf("Press s to move down\n");
  printf("Press d to move right\n");

  return map;
}

int main(int argc, char* argv[]) {
  int i = 0, j = 0;

   /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[2]) + 2;
  int cols = atoi(argv[1]) + 2;

  int* player = initPlayer();
  int* cars = initCars(rows, cols);
  char* carState = initCarState(cols);
  char** map = initMap(rows, cols, player, cars, carState);

  if(cols % 2 == 0) {
    printf("Even number of columns, cya l8r allig8r");
    return 0;
  } else if(rows - 2 < 3) {
    printf("The number of rows can't be less than 3, exiting program");
    return 0;
  } else if(cols - 2 < 5) {
    printf("The number of columns can't be less than 5, exiting program");
    return 0;
  }

  while(TRUE) {
    updateMap(rows, cols, player, cars, carState, map);

    if (player[1] == rows - 2) {
      if (player[0] == cols - 2) {
        printf("Winny winny chicky dinner\n");
        return 0;
      }
    }

    if(player[0] % 2 == 0) {
      if(player[1] == cars[player[0]]) {
        printf("You lose!\n");
        return 0;
      }
    }

    newSleep(0.25);
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