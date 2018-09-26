#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signal_no){
    if (signal_no == SIGINT)
        printf("Get sigint \n");   
        exit(1) ; 
}

int main(){
    signal(SIGINT, handler);
    printf("Start \n ");

    while (1);

   
    return 0;
}
