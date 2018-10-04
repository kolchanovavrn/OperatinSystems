

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> 
int main(int argc, char **argv) { 
    int n;
    printf("N: ");
    scanf("%d", &n);
                   
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        *(arr + i) = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    free(arr);
                                      
    return(0); 
} 
