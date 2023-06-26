#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    ll mx = 0;
    ll x, y;
 
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        mx = max(mx, x+y);
    }
 
    cout << mx<<endl;
 
    return 0;
}