#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 35;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=2; i<=n; i++)
    {
        ll jay = n / i;
        ans += (jay*(jay+1))/2 - 1;
    }
 
    cout << 4*ans << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 