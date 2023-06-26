#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int min_idx(const string &s, const int l, const int r)
{
    char c = 'z';
    for(int i=l; i<r; i++)
        c = min(c,s[i]);
    for(int i=r-1; i>=l; i--)
    {
        if(s[i] == c)
            return i;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    string s;
    cin >> s;
    int n = (int)s.length();
 
    vector<bool> ans(n,0);
 
    int idx = n;
    while(idx > 0)
    {
        int now = min_idx(s,0,idx);
        if(now+1 == idx && idx != n)
        {
            ans[now] = 0;
            if(now)
                ans[now-1] = 1;
        }
        else
        {
            ans[now] = 1;
            if(now)
                ans[now-1] = 1;
        }
        idx = now;
        //cout << idx << endl;
    }
 
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 