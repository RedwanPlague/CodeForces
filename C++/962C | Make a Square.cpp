#include <bits/stdc++.h>
using namespace std;
 
#define MX 50005
 
int dp[15][15];
int vis[15][15], mark;
 
int lcs(string &a, string &b, int i, int j)
{
   if(i >= a.length() || j >= b.length())
      return 0;
   if(vis[i][j] == mark)
      return dp[i][j];
   vis[i][j] = mark;
   if(a[i] == b[j])
      return (dp[i][j] = 1 + lcs(a, b, i+1, j+1));
   return (dp[i][j] = max(lcs(a, b, i+1, j), lcs(a, b, i, j+1)));
}
 
string toString(long long n)
{
   string s = "";
   while(n)
   {
      s += ('0' + n%10);
      n /= 10;
   }
   reverse(s.begin(), s.end());
   return s;
}
 
int main()
{
   string in;
   cin>>in;
 
   vector <string> v;
 
   for(long long i = 1LL; i < MX; i++)
   {
      v.push_back(toString(i*i));
      //cout<<toString(i*i)<<endl;
   }
 
   int minDlt = 200;
 
   for(int i=0; i<v.size() && v[i].length() <= in.length(); i++)
   {
      mark++;
      int Lcs = lcs(in, v[i], 0, 0);
      if(Lcs == v[i].length())
      {
         //cout<<v[i]<<' '<<Lcs<<endl;
         minDlt = min(minDlt, (int)in.length() - Lcs);
      }
   }
 
   if(minDlt == 200)
      cout<<-1<<endl;
   else
      cout<<minDlt<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 