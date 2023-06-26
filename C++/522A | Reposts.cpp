#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
 
typedef vector<int> vi;
 
void lower(string &s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }
}
 
int dfs(const int cur, const vector<vi> &adj)
{
    int ret = 0;
    for(int i=0; i<adj[cur].size(); i++)
        ret = max(ret, dfs(adj[cur][i], adj));
    return (1 + ret);
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif // ONLINE_JUDGE
 
    int n;
    cin >> n;
 
 map <string,int> mp;
 mp["polycarp"] = 0;
 int cnt = 1;
 
 vector<vi> adj(n+1);
 
 string u, dummy, v;
 for(int i=0; i<n; i++)
 {
     cin >> u >> dummy >> v;
     lower(u);
     lower(v);
     if(mp.find(u) == mp.end())
         mp[u] = cnt++;
     else if(mp.find(v) == mp.end())
         mp[v] = cnt++;
     adj[ mp[v] ].push_back(mp[u]);
 }
 
 cout << dfs(0,adj) << endl;
 
 return 0;
}