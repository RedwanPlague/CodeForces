#include <iostream>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   string cards;
 
   cin>>cards;
 
   int cnt = 0;
 
   for(int i=0; i<cards.length(); i++)
   {
      char& c = cards[i];
      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
         cnt++;
      if(c >= '0' && c <= '9' && (c-'0')&1)
         cnt++;
   }
 
   cout<<cnt<<endl;
 
   return 0;
}
 