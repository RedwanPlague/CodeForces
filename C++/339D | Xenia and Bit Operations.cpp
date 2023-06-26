#include <cstdio>
 
const int mx = (1<<17) + 1;
 
int a[mx];
int tree[3*mx];
 
int init(int cur, int l, int r, int op)
{
    if(l == r)
    {
        tree[cur] = a[l];
        return tree[cur];
    }
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    int ret1 = init(left, l, mid, 1-op);
    int ret2 = init(right, mid+1, r, 1-op);
    //printf("%d %d\n", ret1, ret2);
    if(op)
        tree[cur] = ret1 | ret2;
    else
        tree[cur] = ret1 ^ ret2;
    return tree[cur];
}
 
int update(int cur, int l, int r, int op, int at, int val)
{
    if(at < l || at > r)
        return tree[cur];
    if(l == r)
    {
        tree[cur] = val;
        return tree[cur];
    }
    int left = cur << 1;
    int right = left + 1;
    int mid = (l + r) >> 1;
    int ret1 = update(left, l, mid, 1-op, at, val);
    int ret2 = update(right, mid+1, r, 1-op, at, val);
    //printf("%d %d\n", ret1, ret2);
    if(op)
        tree[cur] = ret1 | ret2;
    else
        tree[cur] = ret1 ^ ret2;
    return tree[cur];
}
 
int main()
{
    int n, m, at, val;
    scanf("%d %d", &n, &m);
    int limit = (1<<n);
    for(int i=1; i<=limit; i++)
    {
        scanf("%d", a+i);
    }
    init(1, 1, limit, n&1);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &at, &val);
        printf("%d\n", update(1, 1, limit, n&1, at, val));
    }
    return 0;
}