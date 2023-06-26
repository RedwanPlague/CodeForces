#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define pb push_back
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
 
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<string> s(n), r(n);
    set<string> st;
    for(int i=0; i<n; i++)
    {
        cin >> r[i];
        reverse(r[i].begin(),r[i].end());
        s[i] = r[i];
        reverse(s[i].begin(),s[i].end());
        st.insert(s[i]);
    }
    string ans, mid;
    for(int i=0; i<n; i++)
    {
        if(s[i] == r[i])
            mid = s[i];
        else if(st.find(r[i]) != st.end())
        {
            ans += s[i];
            st.erase(s[i]);
            st.erase(r[i]);
        }
    }
    cout << ans.size()*2+mid.size() << endl;
    cout << ans;
    reverse(ans.begin(),ans.end());
    cout << mid;
    cout << ans;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 