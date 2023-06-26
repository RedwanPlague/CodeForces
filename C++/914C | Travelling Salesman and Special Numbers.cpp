#include <iostream>
#include <algorithm>
using namespace std;
 
#define MOD 1000000007
#define MAX 1005
 
int order[MAX];
int comb[MAX][MAX];
 
int popcount(int bin)
{
   int count = 0;
   for(int i=0; i<32; i++)
   {
      if((bin>>i)&1)
         count++;
   }
   return count;
}
 
void setOrder()
{
   order[1] = 0;
   for(int i=2; i<MAX; i++)
   {
      order[i] = 1 + order[popcount(i)];
   }
}
 
void setComb()
{
   for(int i=0; i<MAX; i++)
   {
      comb[i][0] = 1;
   }
   for(int i=1; i<MAX; i++)
   {
      for(int j=1; j<MAX; j++)
      {
         comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
      }
   }
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   string n;
   int k;
   cin>>n>>k;
 
   if(k==0)
   {
      cout<<"1\n";
      return 0;
   }
   if(k==1)
   {
      int start = 0;
      while(n[start] == '0') start++;
      cout<<n.size()-start-1<<endl;
      return 0;
   }
 
   setOrder();
   setComb();
 
   int ones = 0;
   long long ans = 0;
 
   for(int pos=0; pos<n.size(); pos++)
   {
      if(n[pos] == '0') continue;
 
      for(int x=max(ones,1); x<MAX; x++)
      {
         if(order[x] == k-1)
            ans = (ans + comb[n.size()-pos-1][x-ones])%MOD;
      }
 
      ones++;
   }
 
   if(order[ones] == k-1)
      ans = (ans+1)%MOD;
 
   cout<<ans<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 