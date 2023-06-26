#include <stdio.h>
 
int prm(int n)
{
    int i;
    for(i=2; i*i<=n; i++)
        if(n%i==0)
            break;
    if(i*i<=n)
        return 1;
    else
        return 0;
}
 
int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=4; 2*i<n; i++)
        if(prm(i) && prm(n-i))
            break;
    printf("%d %d\n", i, n-i);
    return 0;
}