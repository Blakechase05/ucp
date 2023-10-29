#ifndef PLAYER_H
#define PLAYER_H

  typedef struct player {
    int x;
    int y;
  } Player;

  Player* initPlayer(int rows, int cols, int** intMap);
  Player* updatePlayer(int rows, int cols, char input, Player* player);

#endif