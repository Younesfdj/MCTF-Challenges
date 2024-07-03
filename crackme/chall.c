#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void vuln(){
    char buf[9];
    fgets(buf,9,stdin);

    if (strcmp(buf,"13371337") == 0) {
        printf("Welcome home! here's your flag:\n");
        flag();
    }
    else{
        puts("Sorry, wrong password!");
    }
}

int main(){
    setup();
    puts("Type the MC HQ password to enter:");
    vuln();

    return 0 ;
}