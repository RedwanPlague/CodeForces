#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 107
#define MAX 30
 
int main()
{
   ios_base::sync_with_stdio(0); /*cin.tie(0); cout.tie(0);*/
   int n, s, f;
   cin>>n;
   ll cum[2*n+2];
   cum[0] = 0;
   for(int i=1; i<=n; i++)
   {
      cin>>cum[i];
      cum[i] += cum[i-1];
   }
   for(int i=n+1; i<=2*n; i++)
   {
      cum[i] = cum[n]+cum[i-n];
   }
   cin>>s>>f;
   ll maxPar = -1;
   int hour = 1;
   for(int h = 1; h<=n; h++)
   {
      ll many = cum[n+f-h] - cum[n+s-h];
      //cout<<many<<endl;
      if(many > maxPar)
      {
         maxPar = many;
         hour = h;
      }
   }
   cout<<hour<<endl;
   return 0;
}
 