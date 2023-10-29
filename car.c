#include <stdio.h>
#include <stdlib.h>

#include "car.h"

Car* initCar(int rows, int cols, int** intMap, Car* car) {
  int i, j;
  
  car->state = '>';

  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 2) {
        car->x = j;
        car->y = i;
      }
    }
  }

  return car;
}