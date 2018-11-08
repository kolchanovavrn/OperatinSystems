lude <string.h>
#include <stdio.h>

int main()
{

    FILE* fp = fopen("/dev/urandom", "r");
    for (int i = 0; i < 20; i++){
        char el;
        fscanf(fp,"%c",&el);
        printf("%c", el);
    }
    printf("\n");
    fclose(fp);
    return 0;

}
