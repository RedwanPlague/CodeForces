#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
 int T;
 cin >> T;
 while(T--)
 {
  int a, b;
  cin >> a >> b;
  if(a%b == 0)
   cout << "0\n";
  else
   cout << b-a%b << '\n';
 }
 
    return 0;
}