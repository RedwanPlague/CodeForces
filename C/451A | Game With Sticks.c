#include <stdio.h>
int main()
{
    int m, n, i;
    scanf("%d %d", &m, &n);
    i = (m<n) ? m%2 : n%2 ;
    if(i)
        printf("Akshat\n");
    else
        printf("Malvika\n");
    return 0;
}