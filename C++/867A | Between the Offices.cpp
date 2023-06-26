#include <iostream>
#include <string>
using namespace std;
int main()
{
   int n, stof = 0, ftos = 0;
   cin>>n;
   string s;
   cin>>s;
   for(int i=0; i<n-1; i++)
   {
      if(s[i]=='S' && s[i+1]=='F')
         stof++;
      else if(s[i]=='F' && s[i+1]=='S')
         ftos++;
   }
   if(stof>ftos)
      cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;
   return 0;
}