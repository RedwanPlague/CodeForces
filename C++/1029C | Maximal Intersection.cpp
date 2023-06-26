#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
    vi l(n), r(n);
    vector<ii> p(n);
    for(int i=0; i<n; i++)
    {
        cin>>l[i]>>r[i];
        p[i].first = l[i];
        p[i].second = r[i];
    }
 
    sort(l.begin(), l.end(), greater<int>());
    sort(r.begin(), r.end());
 
    int mx = r[0]-l[0];
 
    if(n == 1)
    {
        cout<<mx<<endl;
        return 0;
    }
 
    for(int i=0; i<n; i++)
    {
        int nl, nr;
        if(p[i].first == l[0])
            nl = l[1];
        else
            nl = l[0];
        if(p[i].second == r[0])
            nr = r[1];
        else
            nr = r[0];
        mx = max(mx, nr-nl);
    }
 
    if(mx < 0)
        mx = 0;
    cout<<mx<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 