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