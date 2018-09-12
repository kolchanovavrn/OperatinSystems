
#include <stdio.h>
#include <sys/types.h>

#define N 15
int main(){
  int i, PID;
    
  fork();
  
  PID = getpid();

  printf("Hello from parent %d \n", PID - N);
  printf("Hello from child %d \n", PID - N);
  
  return 0;
}
