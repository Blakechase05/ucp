#ifndef MAIN_H
#define MAIN_H

char** initMap(int rows, int cols, int* player, int* cars, char* carState);
int* initCars(int rows, int cols);
char* initCarState();
int* initPlayer();
int* updatePlayer(int rows, int cols, int* player, char** map);
void updateMap(int rows, int cols, int* player, char** map);

#endif