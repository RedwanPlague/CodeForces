#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, m;
   cin>>n>>m;
 
   if(n > 27)
      cout<<m<<endl;
   else
      cout<<(m % (1<<n))<<endl;
 
   return 0;
}