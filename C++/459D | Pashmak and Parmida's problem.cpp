#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
 
#define MX 1000005
 
int n;
int a[MX], bef[MX], aft[MX];
int tree[MX];
 
int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= ( idx & (-idx) );
    }
    return sum;
}
 
void update(int idx, int add)
{
    while(idx <= n)
    {
        tree[idx] += add;
        idx += ( idx & (-idx) );
    }
}
 
int main()
{
    map <int,int> mp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", a+i);
        mp[a[i]]++;
        bef[i] = mp[a[i]];
    }
    mp.clear();
    for(int i=n-1; i>=0; i--)
    {
        mp[a[i]]++;
        aft[i] = mp[a[i]];
    }
    mp.clear();
    memset(tree, 0, sizeof(tree));
 
    long long sum = 0;
 
    for(int i=n-1; i>=0; i--)
    {
        sum += query(bef[i]-1);
        update(aft[i], 1);
        //printf("%lld\n", sum);
    }
 
    printf("%I64d\n", sum);
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 