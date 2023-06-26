#include <stdio.h>
int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int min = (n<m)?n:m;
    printf("%d\n", min+1);
    for(i=0; i<=min; i++) printf("%d %d\n", i, min-i);
    return 0;
}