#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll n, m, ans;
 
    cin >> n>> m;
 
    if(n > m)
        swap(n,m);
 
    if(n == 1)
    {
        ll del = 2*max(0LL,(m*n)%6-3);
        ans = m*n - ( (m*n)%6 - del );
    }
    else if((n&1) && (m&1))
    {
        ans = m*n-1;
    }
    else
    {
        if(n == 2 && m == 2)
            ans = 0;
        else if(n == 2)
        {
            if(m == 3)
                ans = 4;
            else if(m == 7)
                ans = 12;
            else
                ans = m*n;
        }
        else
            ans = m*n;
    }
 
    cout << ans << endl;
 
    return 0;
}