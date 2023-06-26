#include <stdio.h>
int main()
{
    int k, w, n, d;
    scanf("%d %d %d", &k, &n, &w);
    d=w*(w+1)*k/2;
    d=d-n;
    if(d<0)
        d=0;
    printf("%d", d);
    return 0;
}