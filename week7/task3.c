#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand(time(NULL));

    printf("Give me the size of the array: ");
    
    int arr1_size;
    scanf("%d", &arr1_size);
    int* a1 = calloc(arr1_size, sizeof(int));

    for (int i = 0; i<arr1_size; i++){
        *(a1 + i) = 100;
        /*Checkpoint 1*/
        printf("%d", *(a1 + i));
    }
    
    printf("\nGive me new array size: ");
    
    int arr2_size;
    scanf("%d", &arr2_size);
    a1 = realloc(a1, arr2_size*sizeof(int));

    /*Filling by zeroes, if the second array is bigger*/
    if (arr2_size > arr1_size){
        for (int i = arr1_size; i<arr2_size;i++){
            *(a1 + i) = 0;
        }
    }

    for (int i = 0; i<arr2_size; i++){
       /*Checkpoint 2*/
       printf("%d", *(a1 + i)); 
    }
    printf("\n");

    free(a1);

    return 0;

}
