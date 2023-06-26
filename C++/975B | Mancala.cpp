#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   vector <ll> a(14);
   for(int i=0; i<14; i++)
      cin>>a[i];
 
   ll maxS = 0;
 
   for(int time = 0; time < 14; time++)
   {
      if(a[time] == 0)
         continue;
      vector <ll> temp(a);
      int i = (time + 1)%14;
      int pos = (temp[time] % 14);
      ll add = temp[time] / 14;
      temp[time] = 0;
      while(true)
      {
         if(pos > 0)
         {
            temp[i] += add + 1;
            pos--;
            if(i == time)
               break;
            i = (i+1)%14;
         }
         else
         {
            temp[i] += add;
            if(i == time)
               break;
            i = (i+1)%14;
         }
      }
      ll score = 0;
      for(int i=0; i<14; i++)
      {
         //cout<<temp[i]<<' ';
         if(temp[i] % 2 == 0)
            score += temp[i];
      }
      //cout<<endl;
      //cout<<"Score "<<score<<endl;
      maxS = max(maxS, score);
   }
 
   cout<<maxS<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 