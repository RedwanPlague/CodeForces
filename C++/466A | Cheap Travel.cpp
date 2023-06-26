#include <stdio.h>
int main()
{
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int ans=0;
    if(m*a>b) {
        ans+=(n/m)*b;
        n%=m;
        if(n*a>b) ans+=b;
        else ans+=n*a;
    }
    else ans=n*a;
    printf("%d\n", ans);
    return 0;
}