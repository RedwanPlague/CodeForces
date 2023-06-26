#include <bits/stdc++.h>
using namespace std;
 
string a, b;
vector <int> digit;
 
long long closest(long long made, int mask, int taken)
{
   //cout<<"made = "<<made<<endl;
 
   if(taken == digit.size())
   {
      return made;
   }
 
   for(int i=0; i<digit.size(); i++)
   {
      if((mask>>i)&1) continue;
 
      if(digit[i] == b[taken] - '0')
      {
         long long ret = closest(10*made + digit[i], mask | (1<<i), taken+1);
         if(ret == -1)
            break;
         else
            return ret;
      }
   }
 
   for(int i=0; i<digit.size(); i++)
   {
      if((mask>>i)&1) continue;
 
      if(digit[i] < b[taken] - '0')
      {
         made = 10*made + digit[i];
         //cout<<"made = "<<made<<endl;
         mask = mask | (1<<i);
         for(int j=0; j<digit.size(); j++)
         {
            if( ! ((mask>>j)&1) )
            {
               made = 10*made + digit[j];
               //cout<<"made = "<<made<<endl;
            }
         }
 
         return made;
      }
   }
 
   return -1;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   cin>>a>>b;
 
   for(int i=0; i<a.length(); i++)
   {
      digit.push_back(a[i] - '0');
   }
 
   sort(digit.begin(), digit.end());
   reverse(digit.begin(), digit.end());
 
   if(a.length()<b.length())
   {
      for(int i=0; i<digit.size(); i++)
      {
         cout<<digit[i];
      }
      return 0;
   }
 
   cout<<closest(0,0,0)<<endl;
 
   return 0;
}