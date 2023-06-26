#include <bits/stdc++.h>
 
using namespace std;
 
#define f(a) ((a-1+x)%n+1)
 
typedef vector<int> vi;
 
class SegTree
{
    vector<vi> ar;
 
    void init(int cur, int l, int r, vi &index)
    {
        if(l == r)
        {
            ar[cur].push_back(index[l]);
            return ;
        }
        int left = cur << 1;
        int right = left + 1;
        int mid = (l+r) >> 1;
        init(left, l, mid, index);
        init(right, mid+1, r, index);
 
        ar[cur].resize(ar[left].size() + ar[right].size());
        int il = 0, ir = 0, ic = 0;
 
        while(il < ar[left].size() && ir < ar[right].size())
        {
            if(ar[left][il] < ar[right][ir])
                ar[cur][ic++] = ar[left][il++];
            else
                ar[cur][ic++] = ar[right][ir++];
        }
        while(il < ar[left].size())
            ar[cur][ic++] = ar[left][il++];
        while(ir < ar[right].size())
            ar[cur][ic++] = ar[right][ir++];
    }
 
public:
 
    SegTree(int n, vi &index)
    {
        ar.resize(4*n);
        init(1,1,n,index);
    }
 
    int query(int cur, int l, int r, int l1, int r1, int l2, int r2)
    {
        if(r < l1 || l > r1)
            return 0;
        if(l1 <= l && r <= r1)
        {
            return (upper_bound(ar[cur].begin(), ar[cur].end(), r2) - lower_bound(ar[cur].begin(), ar[cur].end(), l2));
        }
        int left = cur << 1;
        int right = left + 1;
        int mid = (l+r) >> 1;
        return (query(left, l, mid, l1, r1, l2, r2) + query(right, mid+1, r, l1, r1, l2, r2));
    }
 
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, a;
    cin >> n;
    vi p(n+1), q(n+1); // indexes of each element in the two permutations
 
    for(int i=1; i<=n; i++)
    {
        cin >> a;
        p[a] = i;
    }
    for(int i=1; i<=n; i++)
    {
        cin >> a;
        q[a] = i;
    }
 
    vi index(n+1);
    for(int i=1; i<=n; i++)
        index[p[i]] = q[i]; // mapping the indexes of each element from p to q
 
    SegTree tree(n, index);
 
    int m, b, c, d, l1, r1, l2, r2, x = 0;
    cin >> m;
 
    while(m--)
    {
        cin >> a >> b >> c >> d;
        l1 = min(f(a),f(b));
        r1 = max(f(a),f(b));
        l2 = min(f(c),f(d));
        r2 = max(f(c),f(d));
        //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
        cout << (x = tree.query(1,1,n,l1,r1,l2,r2)) << '\n';
        x++;
    }
 
    return 0;
}