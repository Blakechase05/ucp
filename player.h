#ifndef PLAYER_H
#define PLAYER_H

typedef struct player {
  int x;
  int y;
} Player;

Player* initPlayer(int rows, int cols, int** intMap, Player* player);

#endif