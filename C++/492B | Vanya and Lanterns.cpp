#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int i, n;
    double l;
    cin>>n>>l;
    double a[n];
    for(i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    double mx=a[0];
    for(i=1; i<n; i++) mx=max(mx,(a[i]-a[i-1])/2);
    mx=max(mx,l-a[n-1]);
    printf("%.10lf\n", mx);
    return 0;
}