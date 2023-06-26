#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   string s;
   cin>>s;
   bool valid = true;
   int cntA = 0, cntB = 0, cntC = 0;
   for(int i=0; i<s.length(); i++)
   {
      if(i && s[i] < s[i-1])
         valid = false;
      if(s[i] == 'a')
         cntA++;
      else if(s[i] == 'b')
         cntB++;
      else
         cntC++;
   }
   if(!valid || !cntA || !cntB || !cntC)
      cout<<"NO"<<endl;
   else if(cntC == cntA || cntC == cntB)
      cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;
   return 0;
}