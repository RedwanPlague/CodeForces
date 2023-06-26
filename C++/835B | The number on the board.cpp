#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 int k, S=0;
 string s;
 cin>>k>>s;
 sort(s.begin(),s.end());
 for(auto i: s)
   {
      S += i-'0';
   }
   int cnt = 0, i=0;
   while(S<k)
   {
      S += '9'-s[i++];
      cnt++;
   }
   cout<<cnt<<endl;
 return 0;
}