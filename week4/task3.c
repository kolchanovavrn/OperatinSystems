
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE 124
int main(){
    
    char input[SIZE];
    
    while(1){
        printf("-> ");
        system(fgets(input,SIZE - 1,stdin));

    }
    return 0;
}
