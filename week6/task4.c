#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signal_no){
    switch(signal_no){
        case SIGINT:{
            printf("Get sigint! \n");
            break;
       }
       case SIGKILL:{
            printf("Get sigkill! \n");
            break;
                    }
       case SIGSTOP:{
            printf("Get sigstop! \n");        
            break;
                    }
       case SIGUSR1:{
            printf("Get sigusr1! \n");
            break;
                    }
       default:{
            printf("Get default! :( \n");   
            break;
               }
    }
    exit(0);
}

int main(){
    printf("Start... \n");
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    signal(SIGSTOP, handler);
    signal(SIGUSR1, handler);

    while(1);

    return 0;
}
