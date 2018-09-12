
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    
    char input[25];
    
    while(1){
        printf("$ ");
       
        system(fgets(input,20,stdin));

    }
    return 0;
}
