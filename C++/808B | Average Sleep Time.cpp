#include <stdio.h>
#include <math.h>
int main()
{
    unsigned long long n, k, i;
    unsigned long long S=0;
    scanf("%llu %llu", &n, &k);
    unsigned long long a[n];
    for(i=0; i<n; i++) {
        scanf("%llu", &a[i]);
        S+=k*a[i];
    }
    for(i=0; i<k-1; i++) {
        S-=(k-1-i)*(a[i]+a[n-i-1]);
    }
    printf("%.10lf", (S+0.0)/(n-k+1));
    return 0;
}