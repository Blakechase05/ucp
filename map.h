#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"
#include "player.h"
#include "car.h"
#include "goal.h"

#ifndef MAP_H
#define MAP_H

  int** initIntMap(FILE* fp, int rows, int cols);
  char** initMap(int rows, int cols, Player* player, Car* car, int** intMap);
  char** updateMap(int rows, int cols, Player* player, Car* car, int** intMap, char** map);

#endif