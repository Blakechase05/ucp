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

Car* updateCar(char** map, Car* car) {
  if(car->state == '>') {
    if(map[car->y][car->x + 1] == '.') {
      car->x += 1;
    } else {
      if (map[car->y - 1][car->x] == '.') {
        car->state = '^';
        car->y -= 1;
      } else if (map[car->y + 1][car->x] == '.') {
        car->state = 'v';
        car->y += 1;
      }
    }
  } else if(car->state == '<') {
    if(map[car->y][car->x - 1] == '.') {
      car->x -= 1;
    } else {
      if (map[car->y - 1][car->x] == '.') {
        car->state = '^';
        car->y -= 1;
      } else if (map[car->y + 1][car->x] == '.') {
        car->state = 'v';
        car->y += 1;
      }
    }
  } else if(car->state == '^') {
    if(map[car->y - 1][car->x] == '.') {
      car->y -= 1;
    } else {
      if (map[car->y][car->x - 1] == '.') {
        car->state = '<';
        car->x -= 1;
      } else if (map[car->y][car->x + 1] == '.') {
        car->state = '>';
        car->x += 1;
      }
    }
  } else if(car->state == 'v') {
    if(map[car->y + 1][car->x] == '.') {
      car->y += 1;
    } else {
      if (map[car->y][car->x - 1] == '.') {
        car->state = '<';
        car->x -= 1;
      } else if (map[car->y][car->x + 1] == '.') {
        car->state = '>';
        car->x += 1;
      }
    }
  }

  
  
  return car;
}