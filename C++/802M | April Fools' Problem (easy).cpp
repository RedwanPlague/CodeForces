#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, i;
    unsigned long long S=0;
    scanf("%d %d", &n, &k);
    int a[n];
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a,a+n);
    for(i=0; i<k; i++) S+=a[i];
    printf("%llu", S);
    return 0;
}