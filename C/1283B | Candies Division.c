#include <stdio.h>
 
#define max(a,b) ((a)>(b) ? (a) : (b))
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", n-max(0,n%k-k/2));
    }
    return 0;
}