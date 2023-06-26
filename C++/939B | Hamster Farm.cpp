#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 107
#define MAX 30
 
int main()
{
   ll N, a;
   int K;
   cin>>N>>K;
 
   ll maxHams = -1, type = 1, many = 1;
 
   for(int i=1; i<=K; i++)
   {
      cin>>a;
      if((N/a)*a > maxHams)
      {
         maxHams = (N/a)*a;
         type = i;
         many = (N/a);
      }
   }
 
   cout<<type<<' '<<many<<endl;
 
   return 0;
}
 