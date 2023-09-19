#ifndef MAIN_H
#define MAIN_H

char** initMap(int rows, int cols, int* player, int* cars, char* carState);
int* initCars(int rows, int cols);
char* initCarState(int cols);
int* initPlayer();
int* updatePlayer(int rows, int cols, int* player, char** map);
int* updateCars(int rows, int cols, int* cars, char* carState, char** map);
char** updateMap(int rows, int cols, int* player, int* cars, char* carState, char** map);

#endif