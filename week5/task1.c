
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t threads[10];

void *thread(void *inf){
    printf(" -%ld- thread \n ", (long)inf);
    pthread_exit(NULL);
}


int main(void){
    printf("Parallel: \n");

    for (long i = 0; i < 10; i++){
        pthread_create(&threads[i], NULL, thread, (void *)i);
    }
    
    for (long i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Sequential: \n");
    
    for (long i = 0; i < 10; i++){
        pthread_create(&threads[i], NULL, thread, (void *)i);

        pthread_join(threads[i], NULL);
    }
                   
    return 0;
}


