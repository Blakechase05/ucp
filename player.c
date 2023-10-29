#include <stdio.h>
#include <stdlib.h>

#include "player.h"

Player* initPlayer(int rows, int cols, int** intMap) {
  int i, j;

  Player* player = malloc(sizeof(Player));
  
  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 3) {
        player->x = j;
        player->y = i;
      }
    }
  }

  return player;
}

Player* updatePlayer(int rows, int cols, char input, Player* player) {
  /* Vertical Movement */
  if(input == 'w') {
    if(player->y != 1) {
      player->y -= 1;
    }
  } else if(input == 's') {
    if(player->y != rows - 2) {
      player->y += 1;
    }
  }

  /* Horizontal Movement */
  if(input == 'a') {
    if(player->x != 1) {
      player->x -= 1;
    }
  } else if(input == 'd') {
    if(player->x != cols - 2) {
      player->x += 1;
    }
  }

  return player;
}