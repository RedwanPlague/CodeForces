#include <stdio.h>
int main()
{
    int n, i, a;
    scanf("%d", &n);
    int *z = (int*)calloc(n+5,sizeof(int));
    int *o = (int*)calloc(n+5,sizeof(int));
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        z[i] = z[i-1];
        o[i] = o[i-1];
        if(a)
            o[i]++;
        else
            z[i]++;
    }
    int j, mo = 0, one;
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            one = o[n]-(o[j]-o[i-1])+(z[j]-z[i-1]);
            if(mo<one)
                mo = one;
        }
    }
    printf("%d", mo);
    return 0;
}