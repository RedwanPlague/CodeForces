#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ll l, r;
    cin >> l >> r;
    cout << "YES\n";
    for(ll i=l; i<=r; i+=2)
        cout << i << ' ' << i+1 << br;
    return 0;
}
 