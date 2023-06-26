#include <bits/stdc++.h>
using namespace std;
 
long long n;
int m = 0, k;
 
map<int, int> cnt;
 
int solve()
{
 cin >> n >> k;
 for(int i=0;i<=63;i++) if((n >> i) & 1) cnt[i]++, m++;
 if(m > k) return cout << "No" << endl, 0;
 for(int i=63;i>=-63;i--){
  if(m + cnt[i] <= k)
   m += cnt[i], cnt[i - 1] += cnt[i] * 2, cnt[i] = 0;
  else
   break;
 }
 cout << "Yes" << endl;
 multiset<int> ms;
 for(int i=63;i>=-63;i--) for(int j=0;j<cnt[i];j++) ms.insert(i);
 while(ms.size() < k){
  int u = *ms.begin();
  ms.erase(ms.begin());
  ms.insert(u - 1); ms.insert(u - 1);
 }
 for(auto it=ms.rbegin();it!=ms.rend();it++) cout << *it << " ";
 cout << endl;
    return 0;
}
 
int main()
{
 ios::sync_with_stdio(0);
 solve();
 return 0;
}