#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
struct data
{
    int val, idx;
 
    bool operator<(const data &r) const
    {
        if(val == r.val)
            return (idx < r.idx);
        return (val > r.val);
    }
};
 
struct query
{
    int k, pos, idx;
    bool operator<(const query &r) const
    {
        return (k < r.k);
    }
};
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vi a(n);
    vector<data> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        v[i].val = a[i];
        v[i].idx = i;
    }
 
    sort(all(v));
 
    int m;
    cin >> m;
    vector<query> q(m);
    for(int i=0; i<m; i++)
    {
        cin >> q[i].k >> q[i].pos ;
        q[i].idx = i;
    }
    sort(all(q));
    vi ans(m);
    ordered_set ost;
 
    for(int k=1, i=0, j=0; k<=n; k++)
    {
        ost.insert(v[j++].idx);
        while(i<m && q[i].k == k)
        {
            ans[q[i].idx] = a[*ost.find_by_order(q[i].pos-1)];
            i++;
        }
    }
 
    for(int i=0; i<m; i++)
        cout << ans[i] << '\n';
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 