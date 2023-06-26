#include <stdio.h>
#include <math.h>
#define ll long long
int main()
{
    int n, i, a;
    scanf("%d", &n);
    for(i=1; ; i++) {
        a = (i*(i+1)*(2*i+1))/6+(i*(i+1))/2;
        if(a>2*n) break;
    }
    printf("%d\n", i-1);
    return 0;
}