#include <stdio.h>
int main()
{
    int a, b, i=0;
    scanf("%d %d", &a, &b);
    do {
        a=a*3;
        b=b*2;
        i++;
    } while(a<=b);
    printf("%d", i);
    return 0;
}