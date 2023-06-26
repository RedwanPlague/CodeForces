#include <stdio.h>
int main()
{
    long a,b,l,m,n;
    scanf("%ld %ld %ld", &a,&b,&l);
    m=(a/l);
    n=(b/l);
    if(a%l!=0)
    m++;
    if(b%l!=0)
    n++;
    printf("%.0lf\n", (double)m*n);
    return 0;
}