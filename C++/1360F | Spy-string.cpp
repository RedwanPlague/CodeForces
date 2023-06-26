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
  int n, m;
  cin >> n >> m;
  set<string> st;
  string s;
  for(int i=0; i<n; i++)
  {
   cin >> s;
   st.insert(s);
  }
  vector<string> v;
  for(auto &s: st)
   v.push_back(s);
 
  if(v.size() == 1)
  {
   cout << v[0] << br;
   continue;
  }
 
  string a = v[0];
 
  bool done = false;
  for(int idx = 0; !done && idx < m; idx++)
  {
   for(char c = 'a'; !done && c <= 'z'; c++)
   {
    a = v[0];
    a[idx] = c;
    bool ok = true;
    for(int i=0; ok && i<v.size(); i++)
    {
     int cnt = 0;
     for(int j=0; j<m; j++)
     {
      if(v[i][j] != a[j])
      {
       cnt++;
      }
     }
     if(cnt > 1)
     {
      ok = false;
     }
    }
    if(ok)
    {
     cout << a << br;
     done = true;
    }
   }
  }
  if(!done)
   cout << -1 << br;
 
 }
 
 return 0;
}
 