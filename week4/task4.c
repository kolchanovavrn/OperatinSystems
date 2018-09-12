
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define size 124
int main(){
    
    char input[size];
    int pid;
    int i = 0;
    int k = 0;

    while(1){
        printf("-> ");      
        fgets(input,size - 1, stdin);
        while (input[k] != '\n')
            k++;

        if (input[k-1] != '&'){
            system(input);
        }else {
            input[k-1] = '\0';
            pid = fork();
            system(input);
        }
    }
    return 0;
}
