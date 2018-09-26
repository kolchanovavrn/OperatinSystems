#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){

    int fd[2];
    int pid_buf;
    int status;
    pid_t buffer;

    pid_t child1 = fork(); 
    
    if (child1){
        
        pid_t child2 = fork();
        
        if (child2){
        //parent action
        
            
        pid_buf = pipe(fd);
        close(fd[0]);
        write(fd[1], &child2, sizeof(child2));        
        close(fd[1]);
        printf("Write: Child2 pid is sended... \n");


        waitpid(child2, &status, WUNTRACED | WCONTINUED);
        printf("State: Child2 state is changed... \n");

        }else {
        //child2 action
        }
    }else {
    //child1 action

    close(fd[1]);    
    read(fd[0], &buffer, sizeof(buffer));
    close(fd[0]);

    printf("Read: Child2 pid is readed... \n");

    printf("Waiting: Start... \n");
    sleep(2);
    printf("Waiting: End \n");

        
    
    }

    return 0;
}
