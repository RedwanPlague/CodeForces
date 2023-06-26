#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    ll mx = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }
 
    ll ans = (2*sum-1)/n+1;
    if(n*ans <= 2*sum)
        ans++;
    cout << max(mx,ans) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 