#include <stdio.h>
#include <stdlib.h>

#include "goal.h"

Goal* initGoal(int rows, int cols, int** intMap) {
  int i, j;

  Goal* goal = malloc(sizeof(Goal));
  
  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 4) {
        goal->x = j;
        goal->y = i;
      }
    }
  }

  return goal;
}