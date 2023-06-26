#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
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
  string s;
  cin >> s;
 
  bool ok = true;
  for(int i=1; i<s.size(); i++)
  {
   if(s[i] != s[i-1])
   {
    ok = false;
    break;
   }
  }
  if(ok)
   cout << s << endl;
  else
  {
   string t;
   char prev = '2';
   for(auto c: s)
   {
    if(c == prev)
     t += ('1'-c)+'0';
    t += c;
    prev = c;
   }
   cout << t << endl;
  }
 }
 
 return 0;
}