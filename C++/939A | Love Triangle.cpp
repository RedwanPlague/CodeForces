#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 107
#define MAX 30
 
int main()
{
   int n;
   cin>>n;
   int f[n+1];
   for(int i=1; i<=n; i++)
      cin>>f[i];
   for(int i=1; i<=n; i++)
   {
      if(f[f[f[i]]] == i)
      {
         cout<<"YES"<<endl;
         return 0;
      }
   }
   cout<<"NO"<<endl;
   return 0;
}