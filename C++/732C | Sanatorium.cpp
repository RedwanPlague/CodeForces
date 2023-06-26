#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
int main()
{
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    a[2]--;
    ll ans = max(0,a[2]-a[1])+max(0,a[2]-a[0]);
    cout<<ans<<endl;
    return 0;
}