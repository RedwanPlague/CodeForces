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
 
    string sa, sb, sc;
 
    cin>>n;
    cin>>sa>>sb>>sc;
 
    ll a[1000], b[1000], c[1000];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
 
    for(int i=0; i<sa.length(); i++)
    {
        a[sa[i]]++;
        b[sb[i]]++;
        c[sc[i]]++;
    }
 
    ll maxA = 0, maxB = 0, maxC = 0;
 
    for(int i=0; i<1000; i++)
    {
        maxA = max(maxA, a[i]);
        maxB = max(maxB, b[i]);
        maxC = max(maxC, c[i]);
    }
 
    if(maxA == sa.length() && n == 1)
        maxA--;
    else
        maxA = min(maxA+n, (ll)sa.length());
    if(maxB == sa.length() && n == 1)
        maxB--;
    else
        maxB = min(maxB+n, (ll)sa.length());
    if(maxC == sa.length() && n == 1)
        maxC--;
    else
        maxC = min(maxC+n, (ll)sa.length());
 
    //cout<<maxA<<maxB<<maxC<<endl;
 
    if(maxA > maxB && maxA > maxC)
        cout<<"Kuro"<<endl;
    else if(maxB > maxC && maxB > maxA)
        cout<<"Shiro"<<endl;
    else if(maxC > maxB && maxC > maxA)
        cout<<"Katie"<<endl;
    else
        cout<<"Draw"<<endl;
 
    return 0;
}