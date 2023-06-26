#include <cstdio>
#include <cstring>
 
#define MX 300005
 
int tree[4*MX];
 
void update(int cur, int l, int r, int b, int e, int val)
{
    if(l > r || tree[cur] || r < b || l > e)
        return ;
    if(b <= l && r <= e)
    {
        tree[cur] = val;
        return ;
    }
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    update(left, l, mid, b, e, val);
    update(right, mid+1, r, b, e, val);
}
 
int query(int cur, int l, int r, int at)
{
    if(at < l || at > r)
        return 0;
    if(l == r)
        return tree[cur];
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    int ret1 = query(left, l, mid, at);
    int ret2 = query(right, mid+1, r, at);
    if(ret1)
        return ret1;
    if(ret2)
        return ret2;
    return tree[cur];
}
 
int main()
{
    int n, m, l, r, winner;
    scanf("%d %d", &n, &m);
    memset(tree, 0, sizeof(tree));
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &l, &r, &winner);
        update(1, 1, n, l, winner-1, winner);
        update(1, 1, n, winner+1, r, winner);
 
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d ", query(1, 1, n, i));
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 