#include <iostream>
using namespace std;
 
#define is_vowel(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y')
 
int main()
{
   int n;
   cin>>n;
   char prev = 'b', read;
   for(int i=0; i<n; i++)
   {
      cin>>read;
      if(is_vowel(prev))
      {
         if(!is_vowel(read))
         {
            cout<<read;
            prev = read;
         }
      }
      else
      {
         cout<<read;
         prev = read;
      }
   }
   cout<<endl;
   return 0;
}