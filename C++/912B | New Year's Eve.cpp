#include <iostream>
using namespace std;
 
int main()
{
   long long n, k;
   cin>>n>>k;
 
   if(k == 1)
   {
      cout<<n<<endl;
      return 0;
   }
 
   int pos = 63;
   while(!(n>>pos)) pos--;
 
   cout<<(1LL<<(pos+1))-1<<endl;
 
   return 0;
}