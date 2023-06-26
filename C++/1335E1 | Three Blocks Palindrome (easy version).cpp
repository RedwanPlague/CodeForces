#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
#define MX 200005
#define MXVAL 201
 
int cnt[MXVAL][MX];
 
int maxbetween(int l, int r)
{
 if(r < l)
  return 0;
 int mx = 0;
 for(int a=1; a<MXVAL; a++)
  mx = max(mx, cnt[a][r] - cnt[a][l-1]);
 return mx;
}
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
 int T;
 cin >> T;
 while(T--)
 {
  int n, cur;
  cin >> n;
  vector<vi> idx(MXVAL);
  memset(cnt[0], 0, sizeof(cnt[0]));
  for(int i=1; i<=n; i++)
  {
   cin >> cur;
   idx[cur].push_back(i);
   for(int a=1; a<MXVAL; a++)
    cnt[a][i] = cnt[a][i-1];
   cnt[cur][i]++;
  }
 
  int mxlen = 1;
  for(int a=1; a<MXVAL; a++)
  {
   for(int i = 0, j = idx[a].size()-1, len = 2; i < j; i++, j--, len += 2)
   {
    mxlen = max(mxlen, len + maxbetween(idx[a][i]+1,idx[a][j]-1));
   }
  }
 
  cout << mxlen << '\n';
 }
 
 return 0;
}