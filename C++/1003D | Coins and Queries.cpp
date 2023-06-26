#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 200005;
const int MOD = 1000000007;
 
int lg(int n)
{
    int cnt = 0;
    while(n>1)
    {
        n >>= 1;
        cnt++;
    }
    return cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, q, val;
    cin>>n>>q;
    int two[60];
    memset(two, 0, sizeof(two));
 
    for(int i=0; i<n; i++)
    {
        cin>>val;
        two[lg(val)]++;
    }
 
    /*for(int i=0; i<45; i++)
        cout<<two[i]<<' ';
    cout<<br;*/
 
    ll make;
 
    while(q--)
    {
        cin>>make;
        int ans = 0;
        for(int i=40; i>=0; i--)
        {
            int cnt = make / (1LL<<i);
            ans += min(cnt,two[i]);
            make -= (1LL<<i)*min(cnt,two[i]);
            //cout<<cnt<<' ';
        }
        if(make)
            cout<<-1<<br;
        else
            cout<<ans<<br;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 