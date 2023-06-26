#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
bool possible(vi &v, int moves, int n, int k, int a)
{
    vi cuts({0,n+1});
    for(int i=0; i<moves; i++)
        cuts.push_back(v[i]);
    sort(cuts.begin(), cuts.end());
 
    int cnt = 0;
    for(int i=1; i<cuts.size(); i++)
    {
        cnt += (cuts[i]-cuts[i-1])/(a+1);
    }
 
    return (cnt >= k);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k, a;
    cin >> n >> k >> a;
 
    int m;
    cin >> m;
    vi v(m);
    for(int i=0; i<m; i++)
        cin >> v[i];
 
    if(possible(v,m,n,k,a))
    {
        cout << -1 << endl;
        return 0;
    }
 
    int lo = 1, hi = m, mid;
    while(lo < hi-1)
    {
        mid = (lo+hi)>>1;
        if(possible(v,mid,n,k,a))
            lo = mid+1;
        else
            hi = mid;
    }
 
    cout << ( possible(v,lo,n,k,a) ? hi : lo ) << endl;
 
    return 0;
}