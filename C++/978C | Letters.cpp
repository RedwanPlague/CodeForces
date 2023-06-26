#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    ll room, dorm, a;
    cin>>n>>m;
    vector <ll> v;
    
    v.push_back(0);
    
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(v.back() + a);
    }
    
    for(int i=0; i<m; i++)
    {
        cin>>a;
        dorm = lower_bound(v.begin(), v.end(), a) - v.begin();
        room = a - v[dorm-1];
        cout<<dorm<<' '<<room<<'\n';
    }
    
    return 0;
}