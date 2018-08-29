


#include <stdio.h>
#include <string.h>

void pyramid(int height){
    int i,k,j;
	// This code does magic    
    for (i=1;i<=height;i++){
        for (k = height - ((2*i-1)/2);k>0;k--)
            printf(" ");
        for (j = 2*i-1;j>0;j--){
            printf("*");
        }
        printf("\n");
    }
}

void triangle( int height){
    int i,k;

    for (i = 1; i<=height; i++){
        for (k = i; i>0; i--)
            printf("+");
        printf("\n");
    }
}

void rectangle(int height, int wigth){
    int i,k;

    for (i = 1; i<=height; i++){
        for (k = 1; k<=wigth; k++){
            printf("+");
        }
        printf("\n");
    }
}


void wave(int height){
    int max_wight,i,j;
    int h;
    h = height;
    max_wight = h/2;
    for (i = 1; i<h; i++){
        for (j = 1; j<=max_wight;j++)
            printf("+");

        for (j = max_wight;j>0;j--)
            printf("+");
        printf("\n");
    }

}

int main(){
    char figure_indicator;
    int n;
    printf("Which figure you want to be printed? \n");
    scanf("%c", &figure_indicator);
    printf("Enter the height of the figure: \n");
    scanf("%d",&n);

    /*Можно было, конечно, считать строчку целиком и пользовать strcmp, но тогда пришлось бы без switch/case. Так что не костыль, а "так и было задумано". с:*/
    
    int m;
    switch(figure_indicator){


        case 'w':{
            wave(n);
            break;
            }
        case 'r':{
            printf("Enter the wigth of the figure: \n");
            scanf("%d",&m);
            rectangle(n,m);
            break;
            }
        case 't':{
            triangle(n);
            break;
            }
        case 'p':{
            pyramid(n);
            break;
                 }
    }

    return 0;

}

