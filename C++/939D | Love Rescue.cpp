#include <bits/stdc++.h>
using namespace std;
 
int par[27];
 
int findpar(int r)
{
 if(par[r] == r)
  return r;
 return (par[r] = findpar(par[r]));
}
 
void join(int u, int v)
{
 int up = findpar(u);
 int vp = findpar(v);
 if(up != vp)
   {
      if(up<vp)
         par[vp] = up;
      else
         par[up] = vp;
   }
}
 
int main()
{
 int n;
 string a, b;
 vector < pair<char,char> > ans;
 cin>>n;
 cin>>a>>b;
 
 for(int i=0; i<27; i++)
      par[i] = i;
 
 for(int i=0; i<n; i++)
   {
      if(a[i] == b[i]) continue;
      if(findpar(a[i]-'a') == findpar(b[i]-'a')) continue;
      ans.push_back(make_pair(a[i],b[i]));
      join(a[i]-'a', b[i]-'a');
   }
 
 cout<<ans.size()<<endl;
 for(int i=0; i<ans.size(); i++)
      cout<<ans[i].first<<' '<<ans[i].second<<'\n';
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 