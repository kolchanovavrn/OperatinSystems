
#include <stdio.h>
void swap(int *pn1, int *pn2){
	int temp;
	temp = *pn1;
	*pn1 = *pn2;
	*pn2 = temp;
}

int main(){
	int a, b;
	printf("Enter the numbers, please:\n");
	scanf("%d%d", &a, &b);
	swap(&a,&b);
	printf("Result: ");
	printf("%d, %d \n", a,b);
	return 0 ;
}
