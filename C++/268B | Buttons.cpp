#include <stdio.h>
#define ll long long
int main()
{
    ll n;
    scanf("%lld", &n);
    ll moves = n*n*(n-1)/2-n*(n-1)*(2*n-1)/6+n;
    printf("%lld", moves);
    return 0;
}