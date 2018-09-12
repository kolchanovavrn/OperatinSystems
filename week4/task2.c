
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int i;

    for (i = 1; i <= 5; i++){
        fork();
    }
    printf("Sleep \n");
    sleep(5);
    printf("Asleep \n");

    return 0;
}

