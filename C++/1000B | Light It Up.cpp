#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 100005;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int n, M;
    ll a[MX];
    vector <ll> cumN, cumF;
 
    cin>>n>>M;
 
    for(int i=0; i<n; i++)
        cin>>a[i];
 
    cumN.pb(a[0]);
 
    for(int i=1; i<n; i++)
    {
        if(i&1)
            cumF.pb(a[i] - a[i-1]);
        else
            cumN.pb(a[i] - a[i-1]);
    }
 
    if(n&1)
        cumF.pb(M-a[n-1]);
    else
        cumN.pb(M-a[n-1]);
 
    for(int i=cumN.size()-2; i>=0; i--)
    {
        cumN[i] += cumN[i+1];
    }
    for(int i=cumF.size()-2; i>=0; i--)
    {
        cumF[i] += cumF[i+1];
    }
 
    cumF.pb(0);
    cumN.pb(0);
 
    /*for(int i=0; i<cumN.size(); i++)
        cout<<cumN[i]<<' ';
    cout<<br;
    for(int i=0; i<cumF.size(); i++)
        cout<<cumF[i]<<' ';
    cout<<br;*/
 
    ll maxV = cumN[0];
 
    //cout<<maxV<<br;
 
    if(a[0] > 1)
    {
        maxV =  max(maxV, a[0]-1 + cumF[0]);
        //cout<<a[0]-1 + cumF[0]<<br;
    }
 
    for(int i=0; i<n; i+=2)
    {
        if(i && a[i] > a[i-1] + 1)
        {
            maxV = max(maxV, cumN[0] - cumN[i/2] + a[i]-a[i-1]-1 + cumF[i/2]);
            //cout<<cumN[0] - cumN[i/2] + a[i]-a[i-1]-1 + cumF[i/2]<<br;
        }
 
        if(i < n-1 && a[i+1] > a[i] + 1)
        {
            maxV = max(maxV, cumN[0] - cumN[i/2+1] + a[i+1]-a[i]-1 + cumF[i/2+1]);
            //cout<<cumN[0] - cumN[i/2+1] + a[i+1]-a[i]-1 + cumF[i/2+1]<<br;
        }
    }
 
    if((n&1) && a[n-1] < M-1)
    {
        maxV = max(maxV, cumN[0] - cumN[(n-1)/2+1] + M - a[n-1] - 1);
        //cout<<cumN[0] - cumN[(n-1)/2+1] + M - a[n-1] - 1<<br;
    }
 
    cout<<maxV<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 