#include <stdio.h>
int main()
{
    long long n, m, a=1, b, time=0;
    scanf("%I64d %I64d", &n, &m);
    while(m--) {
        scanf("%I64d", &b);
        if(b>=a) time += b-a;
        else time += n+b-a;
        a=b;
    }
    printf("%I64d", time);
    return 0;
}