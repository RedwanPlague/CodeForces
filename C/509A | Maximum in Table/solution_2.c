#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    if(n==1)
    {
        puts("1");
        return 0;
    }
    n = 2*(n-1);
    long long P = 1;
    for(i=n; i>(n-n/2); i--)
        P *= i;
    for(i=1; i<=(n/2); i++)
        P /= i;
    printf("%I64d", P);
    return 0;
}