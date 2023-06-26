#include <stdio.h>
int abs(int a)
{
    if(a<0)
        a=-a;
    return a;
}
int main()
{
    int i, j, m, n, a;
    for(i=0; i<5; i++)
    for(j=0; j<5; j++) {
        scanf("%d", &a);
        if(a==1) {
            m=i; n=j;
        }
    }
    printf("%d", abs(m-2)+abs(n-2));
    return 0;
}