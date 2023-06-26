#include <iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   if(n==1)
   {
      cout<<"1 1\n1"<<endl;
      return 0;
   }
   cout<<2*(n-1)<<" "<<2<<endl;
   cout<<"1 2"<<endl;
   return 0;
}