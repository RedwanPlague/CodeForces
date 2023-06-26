#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 30
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    ll n;
    int k;
    cin>>n>>k;
 
    while(k--)
    {
        if(n%10 == 0)
            n /= 10;
        else
            n--;
    }
 
    cout<<n<<br;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 