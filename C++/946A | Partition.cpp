#include <iostream>
using namespace std;
 
int main()
{
   int n, a;
   cin>>n;
   int sum = 0;
   for(int i=0; i<n; i++)
   {
      cin>>a;
      if(a>=0)
         sum += a;
      else
         sum -= a;
   }
   cout<<sum<<endl;
   return 0;
}