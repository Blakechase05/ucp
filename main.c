/*
    Yippie! Hooray!
*/

#include <stdio.h>
#include <math.h>

void count(void) {
    static int counter = 0;
    counter++;
    int power = pow(2, counter);
    printf("%d\n", power);
}

int main() {
    count();
    count();
    count();
    count();
    count();
    count();
    count();
    count();
    count();
}