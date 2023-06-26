#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 30
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int par[MX], sz[MX];
 
void init()
{
    for(int i=0; i<MX; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
 
int findpar(int r)
{
    if(r == par[r])
        return r;
    return (par[r] = findpar(par[r]));
}
 
void unite(int a, int b)
{
    int u = findpar(a);
    int v = findpar(b);
    if(u != v)
    {
        if(sz[u] > sz[v])
        {
            par[v] = u;
            sz[u] += sz[v];
        }
        else
        {
            par[u] = v;
            sz[v] += sz[u];
        }
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    string s;
    cin >> n;
 
    vector<bool> used(MX,false);
 
    init();
    for(int i=0; i<n; i++)
    {
        cin >> s;
        for(int i=1; i<s.size(); i++)
            unite(s[i]-'a', s[i-1]-'a');
        for(int i=0; i<s.size(); i++)
            used[s[i]-'a'] = true;
    }
 
    set <int> st;
    for(int i=0; i<26; i++)
        if(used[i])
            st.insert(findpar(i));
 
    cout << st.size() << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 