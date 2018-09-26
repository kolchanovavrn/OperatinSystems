
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int main(){
    int fd[2];
    int func;
    char input[] = "wow";
    char output[3];
    
    func = pipe(fd);
    
    printf("Let's start... \n");
    if (func == 0){
        write(fd[1], input, sizeof(input));
        read(fd[0], output, sizeof(output));

        printf("The moved value is: ");
        printf("%s \n", output);
    }else printf("Error \n");
    
    return 0;
}

