#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
#define MOD 998244353
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
ll tree[4*MX];
ll p[MX], cum[MX], inv[MX];
 
void change(int n)
{
    p[0] = cum[0] = inv[0] = 1;
    for(int i=1; i<=n; i++)
    {
        p[i] = (100*bigmod(p[i],-1))%MOD;
        cum[i] = (cum[i-1]*p[i])%MOD;
        inv[i] = bigmod(cum[i],-1);
    }
}
 
inline ll mul(int l, int r)
{
    if(l > r)
        return 0;
    return (cum[r]*inv[l-1])%MOD;
}
 
void init(int cur, int l, int r) // segtree for range query of E(l,r) [ if only mirrors from l to r existed with no checkpoints in between ]
{
    if(l == r)
    {
        tree[cur] = p[l];
        return ;
    }
    int left = 2*cur;
    int right = left+1;
    int mid = (l+r)/2;
 
    init(left, l, mid);
    init(right, mid+1, r);
 
    tree[cur] = ( (tree[left]*mul(mid+1,r))%MOD + tree[right] ) % MOD;
}
 
ll query(int cur, int l, int r, int b, int e)
{
    if(r < b || e < l)
        return 0;
    if(b <= l && r <= e)
        return tree[cur];
 
    int left = 2*cur;
    int right = left+1;
    int mid = (l+r)/2;
 
    ll ret1 = query(left, l, mid, b, e);
    ll ret2 = query(right, mid+1, r, b, e);
 
    if(!ret1)
        return ret2;
    if(!ret2)
        return ret1;
    return ( (ret1*mul(mid+1,min(e,r)))%MOD + ret2 ) % MOD;
}
 
class BIT
{
    ll tree[MX];
 
public:
 
    BIT()
    {
        memset(tree, 0, sizeof(tree));
    }
 
    ll read(int idx)
    {
        ll sum = 0;
        while (idx > 0)
        {
            sum = (sum + tree[idx]) %MOD;
            idx -= (idx & -idx);
        }
        return sum;
    }
 
    ll readSingle(int idx)
    {
        ll sum = tree[idx];
        if (idx > 0)
        {
            int z = idx - (idx & -idx);
            idx--;
            while (idx != z)
            {
                sum = (sum - tree[idx] + MOD) %MOD;
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
 
    void update(int idx, ll val)
    {
        while (idx <= MX)
        {
            tree[idx] = (tree[idx] + val) %MOD;
            idx += (idx & -idx);
        }
    }
};
 
class OST
{
    int tree[MX];
 
public:
 
    OST()
    {
        memset(tree, 0, sizeof(tree));
    }
 
    int order_of_key(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
 
    void update(int idx, int val)
    {
        while (idx <= MX)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
 
    int find_by_order(int cumFre)
    {
        cumFre--;
 
        int idx = 0, bitMask = 1;
 
        while(!((MX&bitMask) && (MX-bitMask)<bitMask))
        {
            bitMask <<= 1;
        }
 
        while (bitMask)
        {
            int tIdx = idx + bitMask;
            bitMask >>= 1;
            if (tIdx > MX)
                continue;
            if (cumFre >= tree[tIdx])
            {
                idx = tIdx;
                cumFre -= tree[tIdx];
            }
        }
        if (cumFre != 0)
            return -1;
        return idx+1;
    }
};
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, q, u;
    cin >> n >> q;
    for(int i=1; i<=n; i++)
        cin >> p[i];
 
    change(n);
 
    init(1,1,n);
    BIT st; // to store sum of E's,
    OST mt; // to keep track of current checkpoints
    vector<bool> mark(n+2,false);
    mark[1] = true;
    mark[n+1] = true;
    mt.update(1,1);
    mt.update(n+1,1);
    st.update(n,query(1,1,n,1,n)); // initial E with only 1 as checkpoint, this line isn't needed, but seemed like a convension
 
    /*int l, r;
    while(cin >> l >> r)
    {
        cout << query(1,1,n,l,r) << endl;
    }*/
 
    for(int i=0; i<q; i++)
    {
        cin >> u;
        if(mark[u])
        {
            st.update(u-1,(-st.readSingle(u-1)+MOD)%MOD ); // u-1 used to contains E(l,u-1) now it has 0
            int idx = mt.order_of_key(u);
            int l = mt.find_by_order(idx-1); // checkpoint before u
            int r = mt.find_by_order(idx+1); // checkpoint after u
            mt.update(u,-1); // erase u as checkpoint
            mark[u] = false;
 
            ll newE = query(1,1,n,l,r-1);
            st.update(r-1, (newE - st.readSingle(r-1) + MOD) %MOD ); // r-1 used to contain E(u,r-1) now it contains E(l,r-1)
        }
        else
        {
            mt.update(u,1); // add u as checkpoint
            int idx = mt.order_of_key(u);
            int l = mt.find_by_order(idx-1); // checkpoint before u
            int r = mt.find_by_order(idx+1); // checkpoint after u
            mark[u] = true;
 
            ll newE = query(1,1,n,l,u-1);
            st.update(u-1, newE); // u-1 has E(l,u-1) now
            newE = query(1,1,n,u,r-1);
            st.update(r-1, (newE - st.readSingle(r-1) + MOD) %MOD ); // r-1 used to contain E(l,r-1) now it contains E(u,r-1)
        }
 
        cout << st.read(n) << '\n';
    }
 
    return 0;
}