#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
 
    ll each = (l + k -1)/m + 1;
    if(each*m > n)
    {
        cout << -1 << endl;
        return 0;
    }
 
    cout << each << endl;
 
    return 0;
}