#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define FOR(i,n) for(int i=0; i<n; i++)
#define all(v) (v).begin(),(v).end()
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    int t0 = 0, t1=0, k0=0, k1=0;
    int el;
    for(int i=0; i<n; i++)
    {
        cin >> el;
        if(el&1)
            t1++;
        else
            t0++;
    }
    FOR(i,m)
    {
        cin >> el;
        if(el&1)
            k1++;
        else
            k0++;
    }
 
    cout << min(t0,k1) + min(k0,t1) << endl;
 
    return 0;
}