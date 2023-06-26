#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int N, M;
   double minCost = 1000000, a, b;
 
   cin>>N>>M;
 
   for(int i=0; i<N; i++)
   {
      cin>>a>>b;
      if(a/b < minCost)
         minCost = a/b;
   }
 
   cout<<setprecision(10)<<minCost*M<<endl;
 
   return 0;
}