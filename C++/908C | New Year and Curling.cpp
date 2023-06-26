#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int n, r;
   cin>>n>>r;
   int x[n];
   double y[n];
   double hitY, maxY;
 
   cin>>x[0];
   y[0] = r;
   cout<<y[0];
 
   for(int i=1; i<n; i++)
   {
      cin>>x[i];
      maxY = r;
      for(int j=0; j<i; j++)
      {
         if(abs(x[i]-x[j]) <= 2*r)
         {
            hitY = y[j] + sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j]));
            maxY = max(maxY, hitY);
         }
      }
      y[i] = maxY;
 
      cout<<' '<<fixed<<setprecision(10)<<y[i];
   }
 
   return 0;
}
 
 
 
 
 
 
 
 