#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {  
  int i, j = 0;

  if (argc - 1 == 3) {
    printf("Goodbye\n");
    return 1;
  }
  
  for(i = 1; i < argc; i++) {
    printf("You are printing %s\n", argv[i]);
  }


  while(j == 0) {
    printf("Ur mum\n");
  }

  return 0;
}