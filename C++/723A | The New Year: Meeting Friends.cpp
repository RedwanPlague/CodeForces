#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = (a>b)?a:b;
    if(c>max) max=c;
    int min = (a<b)?a:b;
    if(c<min) min=c;
    printf("%d", max-min);
    return 0;
}