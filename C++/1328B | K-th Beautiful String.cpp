#include <iostream>
#include <string>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
 int T;
 cin >> T;
 while(T--)
 {
  int n;
  ll k;
  cin >> n >> k;
  ll lim = (ll)n*(n-1)/2;
  k = lim - k;
  string s(n,'a');
  for(int i=n-1; i>0; k-=i, i--)
  {
   if(k < i)
   {
    s[n-1-i] = s[n-1-i+k+1] = 'b';
    break;
   }
  }
  cout << s << endl;
 }
 
    return 0;
}