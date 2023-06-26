#include <bits/stdc++.h>
using namespace std;
int main()
{
   int d, n, i, solve=0;
   cin>>n>>d;
   int *a = (int*)calloc(n+2, sizeof(int));
   for(i=0; i<n; i++)
      cin>>a[i];
   sort(a,a+n);
   i = 0;
   while(i<n)
   {
      if(2*d>=a[i])
         d = max(d,a[i++]);
      else
      {
         d *= 2;
         solve++;
      }
      //printf("%d %d\n", i, d);
   }
   cout<<solve<<endl;
   return 0;
}