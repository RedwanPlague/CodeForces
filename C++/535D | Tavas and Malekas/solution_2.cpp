#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
#define MOD 1000000007
 
typedef long long ll;
typedef vector<int> vi;
 
ll bigMod(ll base, ll pw)
{
    ll ret = 1, mul = base;
    while(pw)
    {
        if(pw&1)
            ret = (ret*mul)%MOD;
        mul = (mul*mul)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
vi kmp(const string &s)
{
    int n = (int)s.size();
    vi pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    vi idx(m);
    for(int i=0; i<m; i++)
    {
        cin >> idx[i];
        idx[i]--;
    }
 
    vi pi = kmp(p);
 
    int len;
    ll ans = 1LL;
    for(int i=1; i<m; i++)
    {
        len = idx[i-1] + p.size() - idx[i];
        if(len <= 0)
            continue;
        int j = p.size()-1;
        while(j > 0 && pi[j] > len)
            j = pi[j-1];
        if(pi[j] != len)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    if(m && idx.back()+p.size() > n)
    {
        cout << 0 << endl;
        return 0;
    }
 
    int cnt = 0;
    for(int i=0, j=0; i<m; i++)
    {
        j = max(j,idx[i]);
        cnt += (idx[i]+p.size()-j);
        j = idx[i]+p.size();
    }
 
    cout << bigMod(26,n-cnt) << endl;
 
    return 0;
}