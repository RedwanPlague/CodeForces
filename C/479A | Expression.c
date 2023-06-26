#include <stdio.h>
int main()
{
    int a, b, c, S, X;
    scanf("%d %d %d", &a, &b, &c);
    S=a*b*c;
    X = a+b+c;
    if(X>S)
        S=X;
 
    X = (a+b)*c;
    if(X>S)
        S=X;
 
    X = a*(b+c);
    if(X>S)
        S=X;
 
    X = a*b+c;
    if(X>S)
        S=X;
 
    X = a+b*c;
    if(X>S)
        S=X;
    printf("%d", S);
    return 0;
}