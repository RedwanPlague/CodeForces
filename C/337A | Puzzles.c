#include <stdio.h>
int main()
{
    int i, j, n, m;
    scanf("%d %d", &n, &m);
    unsigned long long a[m], x;
    for(i=0; i<m; i++)
        scanf("%I64d", &a[i]);
    for(i=0; i<(m-1); i++)
        for(j=i+1; j<m; j++)
    if(a[i]>a[j]) {
        x=a[i];
        a[i]=a[j];
        a[j]=x;
    }
    x=1000000005;
    for(i=0; i<=(m-n); i++)
        if( x > (a[i+n-1]-a[i]))
            x = (a[i+n-1]-a[i]);
    printf("%I64d\n", x);
    return 0;
}