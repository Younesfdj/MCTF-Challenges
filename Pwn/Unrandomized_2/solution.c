#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 100;
        printf("The random number is %d\n", random_number);
    }
    return 0;
}