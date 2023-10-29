#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"

#define FALSE 0
#define TRUE !FALSE

struct Obj {
  int x;
  int y;
};

struct Car {
  int x;
  int y;
  char state;
};

int main(int argc, char* argv[]) {
  int i, j, rows, cols;

  char input;

  struct Car car;
  struct Obj player;
  struct Obj goal;

  int** intMap;
  char** map;

  /* 
      OPENING AND READING THE FILE CONTENTS
  */
  /* File pointer to <fileName>.txt */
  FILE* fp = fopen(argv[1], "r");

  /* Check there's an input for fp */
  if(fp != NULL) {
    /* Check for errors when doing anything with the file */
    if(ferror(fp)) {
      perror("Error reading from text file.");
    }
    
    fscanf(fp, "%d %d", &rows, &cols);
    /* Add 2 slots onto rows and cols for the border */
    rows += 2;
    cols += 2;

    /* Malloc the 2D array to store our integers from the file */
    intMap = (int**)malloc(rows * sizeof(int*));
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

  } else {
    perror("Cannot open file");
  }

  /*
      PLAYER STUFF
  */
  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 3) {
        player.x = j;
        player.y = i;
      }
    }
  }

  /*
      GOAL STUFF
  */
  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 4) {
        goal.x = j;
        goal.y = i;
      }
    }
  }

  /*
      CAR STUFF
  */
  /* Set the car's initial direction/state */
  car.state = '>';

  for(i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if(intMap[i][j] == 2) {
        car.x = j;
        car.y = i;
      }
    }
  }

  /* 
      CHAR ARRAY 
  */
  map = (char**)malloc(cols * sizeof(char*));
  for (i = 0; i < cols; i++) {
    map[i] = (char*)malloc(rows * sizeof(char));
  }

  /* Update map background */
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

  map[player.y][player.x] = 'P';
  map[car.y][car.x] = car.state;
  
  /* Print map with new updates */
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%c ", map[i][j]);
    }
    printf("\n");
  }

  /*
      WHILE LOOP
  */
  while(TRUE) {
    /*disable and enable buffer stops user from having to press enter */
    disableBuffer();
    scanf(" %c", &input);
    enableBuffer();

    /* 
        PLAYER MOVEMENT 
    */
    /* Vertical Movement */
    if(input == 'w') {
      if(player.y != 1) {
        player.y -= 1;
      }
    } else if(input == 's') {
      if(player.y != rows - 2) {
        player.y += 1;
      }
    }

    /* Horizontal Movement */
    if(input == 'a') {
      if(player.x != 1) {
        player.x -= 1;
      }
    } else if(input == 'd') {
      if(player.x != cols - 2) {
        player.x += 1;
      }
    }

    /*
        CAR MOVEMENT
    */
    if(car.state == '>') {
      if(map[car.y][car.x + 1] == '.') {
        car.x += 1;
      } else {
        if (map[car.y - 1][car.x] == '.') {
          car.state = '^';
          car.y -= 1;
        } else if (map[car.y + 1][car.x] == '.') {
          car.state = 'v';
          car.y += 1;
        }
      }
    } else if(car.state == '<') {
      if(map[car.y][car.x - 1] == '.') {
        car.x -= 1;
      } else {
        if (map[car.y - 1][car.x] == '.') {
          car.state = '^';
          car.y -= 1;
        } else if (map[car.y + 1][car.x] == '.') {
          car.state = 'v';
          car.y += 1;
        }
      }
    } else if(car.state == '^') {
      if(map[car.y - 1][car.x] == '.') {
        car.y -= 1;
      } else {
        if (map[car.y][car.x - 1] == '.') {
          car.state = '<';
          car.x -= 1;
        } else if (map[car.y][car.x + 1] == '.') {
          car.state = '>';
          car.x += 1;
        }
      }
    } else if(car.state == 'v') {
      if(map[car.y + 1][car.x] == '.') {
        car.y += 1;
      } else {
        if (map[car.y][car.x - 1] == '.') {
          car.state = '<';
          car.x -= 1;
        } else if (map[car.y][car.x + 1] == '.') {
          car.state = '>';
          car.x += 1;
        }
      }
    }

    /* Update map background */
    for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
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
    
    /* Update the player's position in the map */
    map[player.y][player.x] = 'P';

    /* Update the car's position in the map */
    map[car.y][car.x] = car.state;

    system("clear");

    /* Print map with new updates */
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        printf("%c ", map[i][j]);
      }
      printf("\n");
    }

    /*
        WIN CONDITION
    */
    if(player.x == goal.x) {
      if(player.y == goal.y) {
        printf("Winner Winner Chicken Dinner!\n");
        return 1;
      }
    }

    /*
        LOSE CONDITION
    */
    if(player.x == car.x) {
      if(player.y == car.y) {
        printf("You Lose!\n");
        return 1;
      }
    }
  }

  /*
      FREEING MEMORY
  */
  for(i = 0; i < rows; i++) {
    free(intMap[i]);
  }
  free(intMap);

  for(i = 0; i < rows; i++) {
    free(map[i]);
  }
  free(map);
  
  return 0;
}