#ifndef CAR_H
#define CAR_H

  typedef struct car {
    int x;
    int y;
    char state;
  } Car;

  Car* initCar(int rows, int cols, int** intMap, Car* car);

#endif