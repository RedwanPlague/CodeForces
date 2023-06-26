#include <iostream>
#include <vector>
using namespace std;
 
#define INF 1000000007
 
int main()
{
   int n, ans = INF;
   cin>>n;
   int a[n];
   vector <int> v;
   int mn = INF;
   for(int i=0; i<n; i++)
   {
      cin>>a[i];
      if(a[i]<mn)
         mn = a[i];
   }
   for(int i=0; i<n; i++)
   {
      if(a[i]==mn)
         v.push_back(i);
   }
   for(int i=1; i<v.size(); i++)
   {
      if(v[i]-v[i-1] < ans)
         ans = v[i]-v[i-1];
   }
   cout<<ans<<endl;
   return 0;
}