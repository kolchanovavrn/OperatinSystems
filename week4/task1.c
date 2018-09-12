
#include <stdio.h>
#include <sys/types.h>

#define N 1
int main(){
  int i, PID;
    
  /*fork();*/
  /*PID = getpid();*/

  PID = fork();
  if(PID > 0) {
        /*parent logic*/
        printf("Hello from parent %d \n", PID - N);

    } else if (PID == 0) {
        printf ("Hello from child %d \n", PID - N);
        /*child logic*/
    } else {
        printf("Error! PID =  %d ", PID - N);
        /*error*/
    }
  /*printf("Hello from parent %d \n", PID - N);
  printf("Hello from child %d \n", PID - N);
  */

  return 0;
}
