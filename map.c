#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "terminal.h"

int** initIntMap(FILE* fp, int rows, int cols) {
  int i, j;
  
  /* Malloc the 2D array to store our integers from the file */
  int** intMap = (int**)malloc(rows * sizeof(int*));
  for (i = 0; i < rows; i++) {
    intMap[i] = (int*)malloc(cols * sizeof(int));
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      intMap[i][j] = 5;
    }
  }

  for (i = 1; i < rows - 1; i++) {
    for (j = 1; j < cols - 1; j++) {
      fscanf(fp, "%d", &intMap[i][j]);
    }
  }

  fclose(fp);

  return intMap;
}

char** initMap(int rows, int cols, Player* player, Car* car,  int** intMap) {
  int i, j;
  
  char** map = (char**)malloc(cols * sizeof(char*));
  
  for (i = 0; i < cols; i++) {
    map[i] = (char*)malloc(rows * sizeof(char));
  }

  /* Init map background */
  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 0) {
        map[i][j] = ' ';
      } else if (intMap[i][j] == 1) {
        map[i][j] = '.';
      } else if (intMap[i][j] == 2) {
        map[i][j] = '.';
      } else if (intMap[i][j] == 3) {
        map[i][j] = ' ';
      } else if (intMap[i][j] == 4) {
        map[i][j] = 'G';
      } else if (intMap[i][j] == 5) {
        map[i][j] = '*';
      }
    }
  }

  map[player->y][player->x] = 'P';
  map[car->y][car->x] = car->state;
  
  /* Print map with new updates */
  system("clear");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%c ", map[i][j]);
    }
    printf("\n");
  }

  return map;
}