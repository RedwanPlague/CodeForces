#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int N, a[100005], in;
   cin>>N;
   memset(a, 0, sizeof(a));
   for(int i=0; i<N; i++)
   {
      cin>>in;
      a[in]++;
   }
   for(int i=0; i<100005; i++)
   {
      if(a[i]&1)
      {
         cout<<"Conan"<<endl;
         return 0;
      }
   }
   cout<<"Agasa"<<endl;
 
   return 0;
}