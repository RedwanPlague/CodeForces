#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    ll n;
    cin>>n;
 
    if(n == 0)
    {
        cout<<0<<endl;
        return 0;
    }
 
    n++;
 
    if(n&1)
        cout<<n<<endl;
    else
        cout<<n/2<<endl;
 
    return 0;
}