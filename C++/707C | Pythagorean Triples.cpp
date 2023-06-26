#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main()
{
 ll n;
 cin>>n;
 if(n<3)
 {
  cout<<"-1";
  return 0;
 }
 if(n&1)
 {
  cout<<(n*n-1)/2<<' '<<(n*n+1)/2;
  return 0;
 }
 int p = 0;
 while(!(n&1))
 {
  n >>= 1;
  p++;
 }
 if(n!=1)
 {
  cout<<(((n*n-1)/2)<<p)<<' '<<(((n*n+1)/2)<<p);
 }
 else
 {
  cout<<(3<<(p-2))<<' '<<(5<<(p-2));
 }
 return 0;
}