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

void check_pass(){
    char buf[9];
    fgets(buf,sizeof(buf),stdin);

    // adding some salt
    int key = 10;
    char result[strlen(buf)];

    for(int i = 0; i < strlen(buf); i++){
        result[i] = buf[i] ^ key;
    }
    result[strlen(buf)] = '\0';

    if (strcmp(result,"13371337") == 0) {
        printf("Welcome again! flag:\n");
        flag();
    }
    else{
        puts("Sorry, wrong password!");
    }
}

int main(){
    setup();
    puts("Type the MC HQ password again: ");
    check_pass();

    return 0 ;
}