#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n/2; i+=2) swap(a[i],a[n-i-1]);
    for(i=0; i<n; i++) cout<<a[i]<<' ';
    return 0;
}