#include <bits/stdc++.h>
using namespace std;
 
#define read(n) scanf("%d", &n)
#define pb push_back
#define id(item) ( lower_bound(idx.begin(), idx.end(), item) - idx.begin() )
 
typedef long long ll;
typedef pair<ll,ll> pii;
 
const int MX = 200005;
const ll INF = (1LL<<62);
 
int tree[16*MX];
 
void inc(int cur, int l, int r, int b, int e)
{
    if(l > e || r < b)
        return ;
    if(b <= l && r <= e)
    {
        tree[cur]++;
        return ;
    }
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    inc(left, l, mid, b, e);
    inc(right, mid+1, r, b, e);
}
 
int query(int cur, int l, int r, int x)
{
    if(l == r)
        return tree[cur];
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    if(x <= mid)
        return tree[cur] + query(left, l, mid, x);
    else
        return tree[cur] + query(right, mid+1, r, x);
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n;
    ll l, r, x;
    cin>>n;
    set <ll> st;
    vector <pii> seg;
    for(int i=0; i<n; i++)
    {
        cin>>l>>r;
        st.insert(l);
        st.insert(r);
        seg.pb(pii(l,r));
    }
    vector <ll> idx;
    idx.pb(-2); // to make it 1 indexed
    for(set <ll> :: iterator it = st.begin(); it != st.end(); it++)
    {
        idx.pb(*it-1);
        idx.pb(*it);
    }
    idx.pb(INF);
    memset(tree, 0, sizeof(tree));
    for(int i=0; i<n; i++)
    {
        inc(1, 1, idx.size(), id(seg[i].first), id(seg[i].second));
    }
 
    ll cnt[MX];
    memset(cnt, 0, sizeof(cnt));
 
    for(int i=2; i<idx.size(); i++)
    {
        if(i&1)
            cnt[query(1, 1, idx.size(), i)] += idx[i+1] - idx[i-1] - 1;
        else
            cnt[query(1, 1, idx.size(), i)]++;
    }
 
    for(int i=1; i<=n; i++)
        cout<<cnt[i]<<' ';
    cout<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 