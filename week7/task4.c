

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void* my_realloc(void *ptr, size_t size);

int main(){
    printf("Enter original array size:");
    int n1;
    scanf("%d",&n1);

    int* a1 = calloc(n1, sizeof(int));

    for (int i = 0; i < n1; i++) {
        *(a1 + i) = 100;
        printf("%d ", *(a1 + i));
    }

    printf("\nEnter new array size: ");
    int n2;
    scanf("%d",&n2);

    a1 = realloc(a1, n2*sizeof(int));


    if (n2 > n1) {
        for (int i = n1; i < n2; i++) {
            *(a1 + i) = 0;
        }
    }

    for (int i = 0; i < n2; i++) {
        printf("%d ", *(a1 + i));
    }
    printf("\n");

    free(a1);

    return 0;
}

void* my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        ptr = malloc(size);
        return ptr;
    }
    if (size == 0) {
        free(ptr);
        return NULL;
   }
   void *new_ptr = malloc(size);
   memcpy(new_ptr, ptr, size);
   free(ptr);
   return new_ptr;
}
