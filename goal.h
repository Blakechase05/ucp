#ifndef GOAL_H
#define GOAL_H

typedef struct goal {
  int x;
  int y;
} Goal;

Goal* initGoal(int rows, int cols, int** intMap);

#endif