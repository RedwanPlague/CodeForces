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
  int a, b, q;
  cin >> a >> b >> q;
  if(a > b)
   swap(a,b);
  int lcm = a/__gcd(a,b)*b;
  while(q--)
  {
   ll l, r;
   cin >> l >> r;
   ll cntl = l/lcm*b;
   cntl += min(l/lcm*lcm+b,l+1) - l/lcm*lcm;
   ll cntr = r/lcm*b;
   cntr += min(r/lcm*lcm+b,r+1) - r/lcm*lcm;
   cout << (r-l+1) - (cntr - cntl + (l%a == (l%b)%a)) << ' ';
  }
  cout << endl;
 }
 
 return 0;
}