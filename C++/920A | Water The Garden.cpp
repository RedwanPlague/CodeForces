#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int T, n, k, time, filled;
   int tap[201];
   int bed[201];
 
   cin>>T;
 
   while(T--)
   {
      cin>>n>>k;
      memset(bed, 0, sizeof(bed));
      filled = 0;
      time = 1;
      for(int i=0; i<k; i++)
      {
         cin>>tap[i];
         bed[tap[i]] = time;
         filled++;
      }
      for(; filled < n; )
      {
         time++;
         for(int i=1; i<=n; i++)
         {
            if(bed[i] == time-1)
            {
               if(i-1>0 && !bed[i-1])
               {
                  bed[i-1] = time;
                  filled++;
               }
               if(i+1<=n && !bed[i+1])
               {
                  bed[i+1] = time;
                  filled++;
               }
            }
         }
         /*for(int i=1; i<=n; i++)
            cout<<bed[i]<<' ';
         cout<<" filled: "<<filled<<'\n';*/
      }
      cout<<time<<'\n';
   }
 
   return 0;
}