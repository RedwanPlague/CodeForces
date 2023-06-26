#include <iostream>
#include <vector>
 
using namespace std;
 
bool possible(const vector<int> &cnt, int k)
{
 int mx = 0, nonz = 0;
 for(auto &x: cnt)
 {
  mx = max(mx,x);
  nonz += (x > 0);
 }
 if(mx < k)
  return false;
 if(mx == k)
  nonz--;
 return (nonz >= k);
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
  int n, a;
  cin >> n;
  vector<int> cnt(n+1);
  for(int i=0; i<n; i++)
  {
   cin >> a;
   cnt[a]++;
  }
  int lo = 0, hi = n/2;
  while(lo < hi-1)
  {
   int mid = (lo+hi)/2;
   if(possible(cnt,mid))
    lo = mid;
   else 
    hi = mid-1;
  }
  if(possible(cnt,hi))
   cout << hi << '\n';
  else
   cout << lo << '\n';
 }
 
 return 0;
}