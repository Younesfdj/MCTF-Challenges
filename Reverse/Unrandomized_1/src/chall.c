#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup(){
    setbuf(stdin,NULL);
    setbuf(stdout,NULL);
    setbuf(stderr,NULL);
}

void flag(){
    FILE* fd = fopen("flag.txt","r");

    if (fd==NULL){
        printf("Error while openning flag.txt\n") ;
        exit(-1) ;
    }

    char flag[0x80];

    fgets(flag,0x80,fd) ;

    printf("%s",flag);

    exit(0) ;
}

int main() {
    setup();
    srand(1337);
    printf("Try to guess all the random numbers correctly and win a gift!\n");

    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 100;
        int guess;
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess != random_number) {
            printf("You failed! The number was %d\n", random_number);
            return 0;
        }
    }
    printf("You did it! Here is your gift: ");
    flag();
    return 0;
}