#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr = (int*)malloc(sizeof(int));
    char *chptr = (char*)malloc(sizeof(char));
    double *dptr = (double*)malloc(sizeof(double));

    int a;
    char ch;
    double dou;

    printf("Enter a integer, character and double : ");
    scanf("%d %c %lf",&a,&ch,&dou);

    *ptr = a;
    printf("%d\n",*ptr);
    free(ptr);

    *chptr = ch;
    printf("%c\n",*chptr);
    free(chptr);

    *dptr = dou;
    printf("%lf\n",*dptr);
    free(dptr);

    return 0;
}