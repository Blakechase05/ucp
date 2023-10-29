#include <stdio.h>
#include <stdlib.h>

#include "car.h"

Car* initCar(int rows, int cols, int** intMap) {
  int i, j;

  Car* car = malloc(sizeof(Car));
  
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