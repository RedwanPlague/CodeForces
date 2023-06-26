#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 109
#define INF 888888888888888888
 
int main()
{
   int k;
   ll n = 0;
 
   cin>>k;
 
   if(k == 1)
   {
      cout<<"4"<<endl;
      return 0;
   }
 
   while(k>1)
   {
      n = 10*n+8;
      k -= 2;
      if(n > INF)
      {
         cout<<"-1"<<endl;
         return 0;
      }
   }
 
   if(k == 1)
      n = 10*n;
 
   if(n > INF)
   {
      cout<<"-1"<<endl;
      return 0;
   }
 
   cout<<n<<endl;
 
   return 0;
}
 