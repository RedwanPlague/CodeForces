#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 15;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    ll n, m, a, b;
    cin>>n>>m>>a>>b;
 
    ll cl = m*((n-1)/m + 1);
    ll costcl = (cl - n)*a;
    ll fl = m*(n/m);
    ll costfl =  (n - fl)*b;
 
    cout<<min(costcl, costfl)<<endl;
 
    return 0;
}