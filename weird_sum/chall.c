#include <stdio.h>
#include <stdlib.h>


// gcc chall.c -o chall -fno-stack-protector -no-pie -m32

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
    short int a = 0;
    short int b = 0;
    printf( "a= ");
    scanf("%hd", &a);
    printf( "b= ");
    scanf("%hd", &b);

    short int sum = a + b;

    if(a < 0 || b < 0){
        puts("No negative numbers allowed!");
        exit(1);
    }
    if (sum == -1337){
        flag();
    }
    else{
        printf("Sum is: %d\n", sum);
    }
}

int main(){
    setup();
    vuln();
    return 0 ;
}