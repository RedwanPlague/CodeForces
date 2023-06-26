#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 1e5+10;
const int MOD = 1e9+7;
 
int n;
int tree[MX];
 
void update(int idx, const int val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
ll two[MX];
 
void twos()
{
    two[0] = 1LL;
    for(int i=1; i<MX; i++)
        two[i] = (two[i-1]*2) % MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    twos();
 
    int q;
    cin >> n >> q;
 
    string s;
    cin >> s;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '1')
            update(i+1,1);
    }
 
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        ll len = r - l + 1;
        ll one = query(r)-query(l-1);
        ll ans = ((two[one]-1)*(two[len-one]))%MOD;
        if(ans < 0)
            ans += MOD;
        cout << ans << "\n";
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 