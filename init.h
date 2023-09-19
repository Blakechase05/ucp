#ifndef INIT_H
#define INIT_H

char** initMap(int rows, int cols, int* player, int* cars, char* carState);
int* initCars(int rows, int cols);
char* initCarState(int cols);
int* initPlayer();

#endif