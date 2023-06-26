#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
 
int main()
{
    int n, k;
    cin>>n>>k;
    int i, a[n], extra=0;
    for(i=0; i<n; i++) cin>>a[i];
    for(i=1; i<n; i++) {
        extra+=max(0,k-a[i]-a[i-1]);
        a[i]+=max(0,k-a[i]-a[i-1]);
    }
    cout<<extra<<endl;
    for(i=0; i<n; i++) cout<<a[i]<<' ';
    return 0;
}