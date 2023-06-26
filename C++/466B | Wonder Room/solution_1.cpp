#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    ll A=6*n;
    if(a*b<A) {
        ll ia, ib, newa=a, newb=b, newA=1e10;
        ll root=ceil(sqrt(A))+1;
        for(ia=a; ia<=root; ia++) {
            ib=ceil((A+0.0)/ia);
            if(ib>=b && ia*ib>=A && ia*ib<newA) {
                newA=ia*ib;
                newa=ia;
                newb=ib;
            }
        }
        for(ia=b; ia<=root; ia++) {
            ib=ceil((A+0.0)/ia);
            if(ib>=a && ia*ib>=A && ia*ib<newA) {
                newA=ia*ib;
                newa=ib;
                newb=ia;
            }
        }
        a=newa;
        b=newb;
    }
    printf("%lld\n%lld %lld\n", a*b, a, b);
    return 0;
}