#include <iostream>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, k, a;
   cin>>n>>k;
 
   int maxNum = -1;
 
   for(int i=0; i<n; i++)
   {
      cin>>a;
      if(k%a == 0 && maxNum < a)
         maxNum = a;
   }
 
   cout<<k/maxNum<<endl;
 
   return 0;
}