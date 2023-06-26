#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
const int INF = 1000000;
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(0);
 int T;
 cin >> T;
 while(T--)
 {
  string n;
  cin >> n;
  int l = n.size();
  vector<vi> next(l+1, vi(3));
  next[l] = {INF, INF, INF};
  for(int i=l-1; i>=0; i--)
  {
   next[i] = next[i+1];
   next[i][n[i]-'1'] = i;
  }
  int mn = INF;
  for(int i=0; i<l; i++)
  {
   int a, b;
   if(n[i] == '1')
   {
    a = 1;
    b = 2;
   }
   else if(n[i] == '2')
   {
    a = 0;
    b = 2;
   }
   else 
   {
    a = 0;
    b = 1;
   }
 
   if(next[i][a] < l)
    mn = min(mn, next[next[i][a]][b] - i + 1);
   if(next[i][b] < l)
    mn = min(mn, next[next[i][b]][a] - i + 1);
  }
 
  if(mn > l)
   mn = 0;
 
  cout << mn << '\n';
 }
 
 return 0;
}