#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
ll bigmod(ll base, ll pw)
{
 ll ret = 1;
 while(pw)
 {
  if(pw&1)
   ret = ret*base %MOD;
  base = base*base %MOD;
  pw >>= 1;
 }
 return ret;
}
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 int T;
 cin >> T;
 while(T--)
 {
  int n;
  cin >> n;
  vector<string> grid(n);
  for(int i=0; i<n; i++)
   cin >> grid[i];
 
  bool ok = true;
  for(int i=0; ok && i<n; i++)
  {
   for(int j=0; ok && j<n; j++)
   {
    if(grid[i][j] == '1')
    {
     bool under = (i == n-1) || (grid[i+1][j] == '1');
     bool right = (j == n-1) || (grid[i][j+1] == '1');
     if(!under && !right)
      ok = false;
    }
   }
  }
 
  if(ok)
   cout << "YES\n";
  else
   cout << "NO\n";
 }
 
 return 0;
}