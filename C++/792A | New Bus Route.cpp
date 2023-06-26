#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
   int i, j, n, min;
   cin >> n ;
   int a[n];
   for(i=0; i<n; i++)
      cin >> a[i] ;
   sort(a, a+n);
   min = a[1] - a[0];
   j=1;     // j being used as counting var.
   for(i=2; i<n; i++) {
      if(min > a[i]-a[i-1]) {
         min = a[i] - a[i-1] ;
         j=1;
      }
      else if(min == a[i] - a[i-1])
         j++;
   }
   cout << min << ' ' << j ;
   return 0;
}