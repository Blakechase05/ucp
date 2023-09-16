#ifndef MAIN_H
#define MAIN_H

char** initMap(int rows, int cols, int* player, int* cars, char* carState);
int* initCars(int rows, int cols);
char* initCarState();
int* initPlayer();
void input(int rows, int cols, char** map);
void update(int rows, int cols, char** map);

#endif