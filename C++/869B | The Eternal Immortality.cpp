#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
   ll a, b;
   cin>>a>>b;
   if(b-a>=5)
   {
      cout<<"0"<<endl;
      return 0;
   }
   int ans = 1;
   for(int i=1; i<=(b-a); i++)
      ans = (ans*(a+i)%10)%10;
   cout<<ans<<endl;
   return 0;
}