#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int N, a, maxNum = -10000000;
 
   cin>>N;
 
   for(int i=0; i<N; i++)
   {
      cin>>a;
      int root = sqrt(a);
      if(root*root != a && maxNum < a)
         maxNum = a;
   }
 
   cout<<maxNum<<endl;
 
   return 0;
}