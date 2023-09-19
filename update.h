#ifndef UPDATE_H
#define UPDATE_H

int* updatePlayer(int rows, int cols, int* player, char** map);
int* updateCars(int rows, int cols, int* cars, char* carState, char** map);
char** updateMap(int rows, int cols, int* player, int* cars, char* carState, char** map);

#endif