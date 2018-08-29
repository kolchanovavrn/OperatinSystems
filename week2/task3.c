#include <stdio.h>

int main(){
	int n;
    scanf("%d", &n);
	int i,j,k;
	for (i = 1; i<=n; i++){
		for (k = n - ((2*i -1)/2); k>0; k-- )
			printf(" "); 
		for (j = 2*i - 1; j>0; j-- ){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
