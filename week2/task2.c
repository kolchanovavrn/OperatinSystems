
#include <stdio.h>
#include <string.h>
#define SIZE 128

int main(){
    char str[SIZE];
    int i;
    printf("Give a string, please: \n");
    for (i = 0; scanf("%c", &str[i]) == 1 && str[i] != '\n'; i++);
    str[i] = '\0';
    printf("Result: \n");
    for (i = strlen(str) - 1; i>=0; i--)
	printf("%c", str[i]);
    return 0;
}

