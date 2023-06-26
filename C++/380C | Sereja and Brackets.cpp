#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 1000005
 
template <int maxn> class SegmentTree
{
    struct Node // each Node repersents a segment
    {
        int len /* longest correct sequence */, ul /* unused '(' */, ur /* unused ')' */;
        Node() : len(0), ul(0), ur(0) {}
    } 
    tree[4*maxn];
    int n;
 
    Node merge(const Node &ret1, const Node &ret2)
    {
        Node ret;
        int use = min(ret1.ul, ret2.ur);
        ret.len = ret1.len + ret2.len + 2*use;
        ret.ul = ret1.ul - use + ret2.ul;
        ret.ur = ret2.ur - use + ret1.ur;
        return ret;
    }
 
    void init(int cur, int l, int r, char *s)
    {
        if(l == r)
        {
            s[l-1] == '(' ? tree[cur].ul++ : tree[cur].ur++;
            return ;
        }
 
        int left = cur << 1;
        int right = left + 1;
        int mid = (l + r) >> 1;
 
        init(left, l, mid, s);
        init(right, mid+1, r, s);
 
        tree[cur] = merge(tree[left], tree[right]);
    }
 
    Node query(int cur, int l, int r, int b, int e)
    {
        if(r < b || e < l)
        {
            return Node();
        }
        if(b <= l && r <= e)
        {
            return tree[cur];
        }
 
        int left = cur << 1;
        int right = left + 1;
        int mid = (l + r) >> 1;
 
        Node ret1 = query(left, l, mid, b, e);
        Node ret2 = query(right, mid+1, r, b, e);
 
        return merge(ret1, ret2);
    }
 
public:
 
    SegmentTree(char *s) : n(strlen(s))
    {
        init(1,1,n,s);
    }
 
    int longest(int b, int e)
    {
        assert(1 <= b && e <= n);
        return query(1,1,n,b,e).len;
    }
};
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    char s[MX];
    scanf("%s", s);
    SegmentTree<MX> segt(s);
 
    int m, b, e;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d %d", &b, &e);
        printf("%d\n", segt.longest(b,e));
    }
 
    return 0;
}