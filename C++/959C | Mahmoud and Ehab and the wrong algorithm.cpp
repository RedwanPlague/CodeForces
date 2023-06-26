#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 101
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   int n;
   cin>>n;
 
   if(n<=5)
      cout<<-1<<endl;
   else
   {
      cout<<1<<' '<<2<<'\n';
      for(int i=3; i<=2+(n-2)/2; i++)
         cout<<1<<' '<<i<<'\n';
      for(int i=3+(n-2)/2; i<=n; i++)
         cout<<2<<' '<<i<<'\n';
   }
 
   for(int i=1; i<n; i++)
      cout<<i<<' '<<i+1<<'\n';
 
   return 0;
}
 