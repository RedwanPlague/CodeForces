#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long 
#define M 1000000007
 
ll mod(ll a, ll b)
{
    if(b==0) return 1%M;
    ll x = mod(a,b/2);
    x = x*x; 
    if(b%2) x = a*x;
    return x%M;
}
 
int main()
{
    ll n, ans;
    cin>>n;
    ans = mod(3,3*n)-mod(7,n);
    if(ans<0) ans += M;
    ans %= M;
    cout<<ans<<endl;
    return 0;
}