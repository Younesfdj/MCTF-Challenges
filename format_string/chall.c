#include <stdio.h>
#include <stdlib.h>


// gcc chall.c -o chall -fno-stack-protector -no-pie -m32

int auth = 0;

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
    char password[100];

    puts("Password: ");
    fgets(password, sizeof password, stdin);
    
    printf(password);
    if(auth == 10) {
        flag();
    }
    else {
        puts("Get out of here kiddo!\n");
        exit(0);
    }
}

int main(){
    setup();
    printf("Auth at %p\n",&auth);

    vuln();
    return 0 ;
}