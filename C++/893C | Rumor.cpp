#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define MX 100005
 
struct Node {
    int idx, gold;
    bool operator<(const Node& other)
    {
        return gold < other.gold;
    }
};
 
vector <int> adj[MX];
bool vis[MX];
 
void dfs(int u)
{
    vis[u] = true;
    for(int i=0; i<adj[u].size(); i++)
        if(!vis[adj[u][i]])
            dfs(adj[u][i]);
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    
 int N, m, u, v;
 cin>>N>>m;
 
 vector <Node> node(N);
 
 for(int i=0; i<N; i++)
 {
     node[i].idx = i+1;
     cin>>node[i].gold;
 }
 
 while(m--)
 {
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 
 sort(node.begin(), node.end());
 
 long long tot_gold = 0;
 
 for(int i=0; i<N; i++)
 {
     if(!vis[node[i].idx])
     {
         tot_gold += node[i].gold;
         dfs(node[i].idx);
     }
 }
 
 cout<<tot_gold<<endl;
 
 return 0;
}