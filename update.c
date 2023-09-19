#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"

/* Update the players position based on the inputs */
int* updatePlayer(int rows, int cols, int* player, char** map) {
  char input;

  /*disable and enable buffer stops user from having to press enter */
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

/* Update the cars positions */
int* updateCars(int rows, int cols, int* cars, char* carState, char** map) {
  int i = 0;
  
  for (i = 0; i < cols; i++) {
    /* If its on the left side, turn it to face right */
    if(carState[i] == '<') {
      if(cars[i] == 2) {
        carState[i] = '>';
      }
      
      /* Update the position by 1 left, leave a . where it used to be */
      map[i][cars[i]] = '.';
      cars[i] = cars[i] - 1;
    
    } else if (carState[i] == '>') {
      /* If its on the right side, turn it to face left */
      if(cars[i] == rows - 3) {
        carState[i] = '<';
      }
      
      /* Update the position by 1 right, leave a . where it used to be */
      map[i][cars[i]] = '.';
      cars[i] = cars[i] + 1;
    }
  }

  return cars;
}

/* Update and print everything, the motherland function */
char** updateMap(int rows, int cols, int* player, int* cars, char* carState, char** map) {
  int i, j = 0;

  /* Set the old player position back to the map before we update the player */
  if(player[0] % 2 == 0) {
    map[player[0]][player[1]] = '.';
  }
  if(player[0] % 2 == 1) {
    map[player[0]][player[1]] = ' ';
  }

  updateCars(rows, cols, cars, carState, map);
  updatePlayer(rows, cols, player, map);

  /* Set the new car states to be on the map */
  for(i = 0; i < cols - 2; i++) {
    map[i][cars[i]] = carState[i];
  }

  /* clear the terminal so its a clean slate before we print again */
  system("clear");

  /* Make sure the background hasn't changed */
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      if(i % 2 == 1) {
        map[i][j] = ' ';
      }
    }
  }

  /* Make sure the border hasn't changed */
  for (i = 0; i < rows; i++) {
    map[0][i] = '*';
    map[cols-1][i] = '*';
  }

  for (i = 0; i < cols; i++) {
    map[i][0] = '*';
    map[i][rows-1] = '*';
  }

  /* Make sure the border hasn't changed */
  map[player[0]][player[1]] = 'P';
  map[cols-2][rows-2] = 'G';

  /* Print map with new updates */
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