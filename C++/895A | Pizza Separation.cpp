#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
 ios_base::sync_with_stdio(false);
 
 int n;
 cin>>n;
 int *a = new int[2*n];
 
 for(int i=0; i<n; i++)
 {
     cin>>a[i];
     a[n+i] = a[i];
 }
 
 int minDif = 400;
 
 for(int i=0; i<n; i++)
 {
     int sum = 0;
     for(int j=i; j<i+n; j++)
     {
         sum += a[j];
         //cout<<i<<' '<<j<<' '<<sum<<endl;
         minDif = min(minDif, abs(360-2*sum));
     }
 }
 
 cout<<minDif<<endl;
 
 delete[] a;
 
 return 0;
}