#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n;
   cin>>n;
   bool a[30];
 
   string s, root;
   set <string> st;
 
   for(int i=0; i<n; i++)
   {
      cin>>s;
      memset(a, 0, sizeof(a));
      for(int j=0; j<s.length(); j++)
      {
         a[s[j]-'a'] = 1;
      }
      root = "";
      for(int j=0; j<30; j++)
      {
         if(a[j])
            root += (char)(j + 'a');
      }
      st.insert(root);
   }
 
   cout<<st.size()<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 