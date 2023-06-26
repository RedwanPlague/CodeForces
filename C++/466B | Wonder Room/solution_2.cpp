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
        int f=0;
        ll root=ceil(sqrt(A))+1;
        if(a>b) {
            a=a^b;
            b=a^b;
            a=a^b;
            f=1;
        }
        for(ia=a; ia<=root; ia++) {
            ib=ceil((A+0.0)/ia);
            if(ib>=b && ia*ib>=A && ia*ib<newA) {
                newA=ia*ib;
                newa=ia;
                newb=ib;
            }
        }
        a=newa;
        b=newb;
        if(f) {
            a=a^b;
            b=a^b;
            a=a^b;
        }
    }
    printf("%lld\n%lld %lld\n", a*b, a, b);
    return 0;
}