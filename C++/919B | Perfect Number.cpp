#include <iostream>
using namespace std;
 
bool isPerfect(int a)
{
   int sum = 0;
   while(a)
   {
      sum += a%10;
      a /= 10;
   }
   if(sum == 10)
      return true;
   return false;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int k, i;
   cin>>k;
 
   for(i=19; k>0; i++)
   {
      if(isPerfect(i))
         k--;
   }
 
   cout<<i-1<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 