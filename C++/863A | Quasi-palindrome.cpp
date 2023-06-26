#include <bits/stdc++.h>
using namespace std;
int main()
{
   int i, j;
   string n;
   cin>>n;
   for(i=n.length()-1; i>=0; i--)
      if(n[i]!='0')
         break;
   for(j=0; j<=i; j++, i--)
   {
      if(n[i]!=n[j])
      {
         cout<<"NO"<<endl;
         return 0;
      }
   }
   cout<<"YES"<<endl;
   return 0;
}