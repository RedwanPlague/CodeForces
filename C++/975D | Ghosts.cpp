#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n;
    ll a, b, x, vx, vy;
    cin>>n>>a>>b;
    map <ll, ll> meet; // how many ghosts from the previous inputs will meet this ghost. [will meet if (a*vx - vy) is same]
    map < pair<ll,ll>, ll > parallel; // how many from 'meet' are parallel to this ghost. [parallel if (vx,vy) is same]
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>x>>vx>>vy;
        sum += (meet[a*vx-vy] - parallel[{vx,vy}]);
        meet[a*vx-vy]++;
        parallel[{vx,vy}]++;
    }
    cout<<2*sum<<endl;
    return 0;
}