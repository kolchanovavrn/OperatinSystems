#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int main(){   
    int fd[2];
    int func;
    pid_t cpid;
    char *str = "wow";
    char buffer[2];

    func = pipe(fd);

    if (func == -1){
        printf("Error! \n");
    }
    
    if (func == 0){
        cpid = fork();
        if (cpid > 0){
            /*Мы, конечно,можем и не закрывать file descriptor,
             который создали pipe-ом,
             т.к  child - копия parent-a и он всё равно сможет записать,
             но давайте сделаем вид, что всё хорошо 
             и есть понимание того что происходит :) */
            close(fd[0]);
            write(fd[1], str, sizeof(str));
            close(fd[1]);
        }else if (cpid == 0){
            close(fd[1]);
            read(fd[0], buffer, sizeof(buffer));
            close(fd[0]);

            printf("Done \n");
        }else printf("Fork error! \n");
    }
    

    return 0;
}


