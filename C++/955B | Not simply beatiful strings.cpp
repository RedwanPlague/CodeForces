#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   string s;
   cin>>s;
   map <char, int> mp;
   for(int i=0; i<s.length(); i++)
   {
      mp[s[i]]++;
   }
   if(mp.size() == 1 || mp.size() >= 5)
   {
      cout<<"No"<<endl;
      return 0;
   }
   if(mp.size() == 4)
   {
      cout<<"Yes"<<endl;
      return 0;
   }
   if(mp.size() == 2)
   {
      map <char, int> :: iterator it = mp.begin();
      if(it->second >= 2 && (++it)->second >= 2)
      {
         cout<<"Yes"<<endl;
         return 0;
      }
      cout<<"No"<<endl;
      return 0;
   }
   map <char, int> :: iterator it = mp.begin();
   if(it->second >= 2 || (++it)->second >= 2 || (++it)->second >= 2)
   {
      cout<<"Yes"<<endl;
      return 0;
   }
   cout<<"No"<<endl;
   return 0;
}
 