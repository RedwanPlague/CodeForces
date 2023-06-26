#include <bits/stdc++.h>
 
#define br '\n'
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
     int n, a;
     cin>>n;
     for(int i=0; i<n; i++)
     {
         cin>>a;
         if(a&1)
            cout<<a<<' ';
         else
            cout<<a-1<<' ';
     }
     cout<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 