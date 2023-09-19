#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "update.h"
#include "random.h"
#include "newSleep.h"
#include "terminal.h"

#define FALSE 0
#define TRUE !FALSE

int main(int argc, char* argv[]) {
  int i = 0, j = 0;

   /* Input rows and coloums from the ./ command */
  int rows = atoi(argv[2]) + 2;
  int cols = atoi(argv[1]) + 2;

  /* Run all the init functions */
  int* player = initPlayer();
  int* cars = initCars(rows, cols);
  char* carState = initCarState(cols);
  char** map = initMap(rows, cols, player, cars, carState);

  /* All of the checks with the input cols and rows */
  if(cols % 2 == 0) {
    printf("Even number of columns, exiting program");
    return 0;
  } else if(rows - 2 < 3) {
    printf("The number of rows can't be less than 3, exiting program");
    return 0;
  } else if(cols - 2 < 5) {
    printf("The number of columns can't be less than 5, exiting program");
    return 0;
  }

  /* MAIN LOOP */
  while(TRUE) {
    updateMap(rows, cols, player, cars, carState, map);

    /* Check for win condition */
    if (player[1] == rows - 2) {
      if (player[0] == cols - 2) {
        printf("Winner Winner Chicken Dinner\n");
        return 0;
      }
    }

    /* Check for lose condition */
    if(player[0] % 2 == 0) {
      if(player[1] == cars[player[0]]) {
        printf("You lost!\n");
        return 0;
      }
    }
  }

  /* Master gave dobby a sock, dobby is freeeee   aka free the malloc'd memory :] */
  for (i = 0; i < cols; i++) {
    free(map[i]);
  }

  free(player);
  free(cars);
  free(carState);
  free(map);

  return 0;
}