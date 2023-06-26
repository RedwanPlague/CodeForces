#include <bits/stdc++.h>
 
#define br '\n'
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MX = 105;
const int MOD = 1000000007;
 
struct Pair
{
    int idx, profit;
    bool operator<(const Pair& other)
    {
        return (other.profit < profit);
    }
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k;
    cin>>n>>k;
    vector <Pair> v(n);
    vector <int> ans;
    for(int i=0; i<n; i++)
    {
        cin>>v[i].profit;
        v[i].idx = i;
    }
 
    sort(v.begin(), v.end());
 
    ll sum = 0;
 
    for(int i=0; i<k; i++)
    {
        ans.pb(v[i].idx);
        sum += v[i].profit;
        //cout<<v[i].idx<<' ';
    }
 
    sort(ans.begin(), ans.end());
 
    int prev = -1;
    cout<<sum<<br;
 
    for(int i=0; i<k-1; i++)
    {
        cout<<ans[i]-prev<<' ';
        prev = ans[i];
    }
 
    cout<<n-1-prev<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 