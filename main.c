#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "linkedlist.h"

#define FALSE 0
#define TRUE !FALSE

int main(int argc, char* argv[]) {
  int i, j, rows, cols;

  char input;

  Node* playerXHead = NULL;
  Node* playerYHead = NULL;

  Node* carXHead = NULL;
  Node* carYHead = NULL;

  Car* car;
  Player* player;
  Goal* goal;

  int** intMap;
  char** map;

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

    intMap = initIntMap(fp, rows, cols);

  } else {
    perror("Cannot open file");
  }

  player = initPlayer(rows, cols, intMap);
  insertStart(&playerXHead, player->x);
  insertStart(&playerYHead, player->y);

  goal = initGoal(rows, cols, intMap);
  
  car = initCar(rows, cols, intMap);
  insertStart(&carXHead, car->x);
  insertStart(&carYHead, car->y);

  map = initMap(rows, cols, player, car, intMap);

  while(TRUE) {
    /* Disable and enable buffer stops user from having to press enter */
    disableBuffer();
    scanf(" %c", &input);
    enableBuffer();

    updatePlayer(rows, cols, input, player);
    insertStart(&playerXHead, player->x);
    insertStart(&playerYHead, player->y);

    updateCar(map, car);
    updateMap(rows, cols, player, car, intMap, map);

    /* WIN CONDITION */
    if(player->x == goal->x) {
      if(player->y == goal->y) {
        printf("Winner Winner Chicken Dinner!\n");
        displayList(playerXHead);
        displayList(playerYHead);
        return 1;
      }
    }

    /* LOSE CONDITION */
    if(player->x == car->x) {
      if(player->y == car->y) {
        printf("You Lose!\n");
        displayList(playerXHead);
        displayList(playerYHead);
        return 1;
      }
    }
  }

  /* FREEING MEMORY */
  for(i = 0; i < rows; i++) {
    free(intMap[i]);
  }
  free(intMap);

  for(i = 0; i < rows; i++) {
    free(map[i]);
  }
  free(map);

  freeList(playerXHead);
  freeList(playerYHead);

  return 0;
}