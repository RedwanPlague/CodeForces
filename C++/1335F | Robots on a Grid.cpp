#include <iostream>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<bool> vb;
 
const int LG = 20;
 
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
  int n, m, range;
  char c;
  cin >> n >> m;
  range = n * m;
  vb color(range);
  vector<vi> nxt(range,vi(LG+1));
  for(int i=0; i<range; i++)
  {
   cin >> c;
   color[i] = c - '0';
  }
  for(int i=0; i<range; i++)
  {
   cin >> c;
   switch(c)
   {
    case 'U': nxt[i][0] = i - m; break;
    case 'D': nxt[i][0] = i + m; break;
    case 'L': nxt[i][0] = i - 1; break;
    case 'R': nxt[i][0] = i + 1; break;
   }
  }
  for(int deg=1; deg<=LG; deg++)
  {
   for(int i=0; i<range; i++)
   {
    nxt[i][deg] = nxt[nxt[i][deg-1]][deg-1];
   }
  }
  set<int> all, black;
  for(int i=0; i<range; i++)
  {
   all.insert(nxt[i][LG]);
   if(!color[i])
    black.insert(nxt[i][LG]);
  }
  cout << all.size() << ' ' << black.size() << '\n';
 }
 
 return 0;
}