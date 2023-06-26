#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   int h, m;
   cin>>h>>m;
   int time = h*60+m;
   int H, D, C, N;
   cin>>H>>D>>C>>N;
   if(time>=1200)
   {
      double cost = ((H-1)/N+1)*(C - C*0.2);
      printf("%.10lf\n", cost);
      //puts(".");
   }
   else
   {
      double cost1 = ((H-1)/N+1)*C;
      //printf("%d %d...", (H-1)/N+1, ((H-1)/N+1)*C);
      double cost2 = (((H+(1200-time)*D)-1)/N+1)*(C - C*0.2);
      printf("%.10lf\n", min(cost1, cost2));
   }
   return 0;
}