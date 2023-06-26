// https://codeforces.com/problemset/problem/1201/C
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
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
 
 int n, k;
 while(cin >> n >> k)
 {
  vi a(n);
  for(int i=0; i<n; i++)
   cin >> a[i];
  sort(all(a));
  a.push_back(INT_MAX);
 
  int mid = n/2;
  int median = a[mid];
  for(int i=mid+1; k && i<=n; i++)
  {
   int diff = a[i] - median;
   if(diff == 0)
    continue;
   int inc = i - mid;
   int use = min(diff,k/inc);
   median += use;
   k -= use*inc;
  }
 
  cout << median << br;
 }
 
 return 0;
}