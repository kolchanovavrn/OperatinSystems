
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int hitAmount = 0;
    int missAmount = 0;
    //fscanf(откуда, что , куда)

    FILE *mf;
    mf = fopen("input.txt", "r");
    scanf("%d" ,&size);
    
    int pages[size];
    int mask[size];
    int isHit;
    int havePlace;
    for (int i = 0; i<size; i++){
        pages[i] = 0;
        mask[i] = 0;
    }
    
    int number;
    
    fscanf(mf,"%d",&number);
    while (!feof(mf)){
        
        isHit = 0;
        havePlace = 0;
        int indexPlace;
        int currMin = 256;
        int indexHit;
        int indexMinVal; 

        for (int i = 0;i<size;i++ ) {
            if (pages[i] == number){
                isHit = 1;
                indexHit = i;
                //printf("Hit address  %d \n", indexHit);
            }
            if (pages[i] == 0) {
                havePlace = 1;
                indexPlace = i;
                //printf("Pages are sim ind = %d , pages[i] = %d \n", indexPlace,pages[i] );
            }
            if (mask[i] < currMin){
                currMin = mask[i];
                indexMinVal = i; 
            }
        } 
       
        if (isHit){
            hitAmount = hitAmount + 1;
            for (int i = 0; i<size; i++){
                mask[i] = mask[i] >> 1;
            }
            mask[indexHit] = mask[indexHit] | 0x80;
            //ox80 hex = 1000 0000 in bin
        }
        else{
            if (havePlace){
                pages[indexPlace] = number;
                missAmount = missAmount + 1;
                for (int i = 0; i<size; i++){
                    mask[i] = mask[i] >> 1;
                }
                mask[indexPlace] = 0x80;
            }
            else{
                pages[indexPlace] = number;
                missAmount = missAmount + 1;
                for (int i = 0; i<size; i++){
                    mask[i] = mask[i] >> 1;
                }
                mask[indexMinVal] = 0x80;
                //check            
            }
        }
        
        fscanf(mf,"%d",&number);
    }

    printf("Hit = %d, Miss = %d \n",hitAmount,missAmount );
    return 0;
}
