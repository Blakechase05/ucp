#include <stdio.h>
#include <stdlib.h>

#ifndef MAP_H
#define MAP_H

  int** initIntMap(FILE* fp, int rows, int cols);
  char** initMap(int rows, int cols, Player* player, Car* car, int** intMap);

#endif