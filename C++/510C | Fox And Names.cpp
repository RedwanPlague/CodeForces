#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
 
using namespace std;
 
typedef vector<int> vi;
 
bool top_sort(const int cur, const vector<vi> &adj, vi &vis, stack<int> &stk)
{
    vis[cur] = 1;
    bool ret = true;
    for(int i=0; ret && i<adj[cur].size(); i++)
    {
        if(i != cur && adj[cur][i])
        {
            if(!vis[i])
                ret = (ret && top_sort(i,adj,vis,stk));
            else if(vis[i] == 1)
                return false;
        }
    }
    vis[cur] = 2;
    stk.push(cur);
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++)
        cin >> s[i];
 
    vector<vi> adj(26,vi(26,0));
 
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int limit = min(s[i].size(), s[j].size());
            int k = 0;
            while(k < limit && s[i][k] == s[j][k])
                k++;
            if(k < limit)
                adj[ s[i][k]-'a' ][ s[j][k]-'a' ] = 1;
            else if(k == limit && s[i].size() > s[j].size())
            {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
 
    vi vis(26,0);
    stack<int> stk;
    bool valid = true;
    for(int i=0; valid && i<26; i++)
    {
        if(!vis[i])
            valid = (valid && top_sort(i,adj,vis,stk));
    }
 
    if(!valid)
        cout << "Impossible" << endl;
    else
    {
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            cout << (char)(top+'a');
        }
        cout << endl;
    }
 
    return 0;
}