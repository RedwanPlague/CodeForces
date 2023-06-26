#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   string s;
   int n;
   cin>>n;
   cin>>s;
 
   if(n == 1)
   {
      cout<<s<<endl;
      return 0;
   }
 
   int cnt = 0;
   for(int i=0; i<n; i++)
   {
      if(s[i] == '0')
         cnt++;
   }
 
   cout<<'1';
   for(int i=0; i<cnt; i++)
      cout<<'0';
   cout<<endl;
 
   return 0;
}