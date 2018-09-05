
#include<stdio.h>

void swap(int *first, int *second){
     int temp;
     *first = *second;
     *second = temp;
}

void bubble_sort(int  array [], int size){
    int i,j;
    for (i = 0; i<size-1; i++){
        for (j = 0; j<size - 1 - i; j++){
            if (array[j] > array[j+1] ){
                swap(&array[j], &array[j+1]);
            }
        }
    }

}

int main (){
    int k = 0;
    int size ;
    
    printf("Give me the size of the array\n");
    scanf("%d",&size);

    int input[size];
    for (k=0; k<size; k++){
        scanf("%d", &input[k]);
    }

    bubble_sort(input, size);
    printf("Sorted array: \n");
    for (k = 0; k<size; k++)
        printf("%d",input[k]);
    printf("\n");
    
    return 0;

}
