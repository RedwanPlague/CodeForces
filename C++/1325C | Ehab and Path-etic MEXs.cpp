#include <iostream>
#include <vector>
 
using namespace std;
 
#define leaf(u) (adj[u].size() == 1)
 
typedef vector<int> vi;
 
int main()
{
 int n, m, u, v;
 cin >> n;
 m = n-1;
 vector<vi> adj(n);
 vi label(m,-1);
 for(int i=0; i<m; i++)
 {
  cin >> u >> v;
  u--; v--;
  adj[u].push_back(i);
  adj[v].push_back(i);
 }
 
 int use = 0;
 for(int i=0; i<n; i++)
 {
  if(leaf(i))
  {
   int id = adj[i][0];
   if(label[id] == -1)
    label[id] = use++;
  }
 }
 for(int i=0; i<m; i++)
 {
  if(label[i] == -1)
   label[i] = use++;
  cout << label[i] << '\n';
 }
 
 return 0;
}