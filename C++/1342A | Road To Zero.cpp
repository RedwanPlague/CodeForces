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
 /* freopen("input.txt", "r", stdin); */
#endif
 
 int T;
 cin >> T;
 while(T--)
 {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  cout << min( b*min(x,y) + abs(x-y)*a , a*(x+y)) << '\n';
 }
 
 return 0;
}