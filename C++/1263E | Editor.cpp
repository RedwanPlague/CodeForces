#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 1000005
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
struct node
{
    int mn, mx, add;
    node() : mn(0), mx(0), add(0) {}
};
 
node tree[4*MX];
 
void push(int cur)
{
    if(tree[cur].add)
    {
        tree[2*cur].add += tree[cur].add;
        tree[2*cur+1].add += tree[cur].add;
        tree[cur].mn += tree[cur].add;
        tree[cur].mx += tree[cur].add;
        tree[cur].add = 0;
    }
}
 
void update(int cur, int curl, int curr, int l, int r, int val)
{
    if(curr < l || r < curl)
    {
        return ;
    }
    if(l <= curl && curr <= r)
    {
        tree[cur].add += val;
        push(cur);
        return ;
    }
 
    push(cur);
 
    int left = 2*cur;
    int right = left+1;
    int mid = (curl+curr)/2;
 
    update(left, curl, mid, l, r, val);
    update(right, mid+1, curr, l, r, val);
 
    tree[cur].mn = min(tree[left].mn + tree[left].add, tree[right].mn + tree[right].add);
    tree[cur].mx = max(tree[left].mx + tree[left].add, tree[right].mx + tree[right].add);
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int s[MX];
    memset(s,0,sizeof(s));
    int cur = 1;
    int n, val;
    cin >> n;
    string com;
    cin >> com;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(com[i] == 'L')
            cur = max(1,cur-1);
        else if(com[i] == 'R')
            cur++;
        else if(com[i] == '(')
        {
            val = 1-s[cur];
            if(val)
                update(1,1,n,cur,n,val);
            s[cur] = 1;
            cnt += val;
            //cout << "update : " << cur << ' ' << val << endl;
        }
        else if(com[i] == ')')
        {
            val = -1-s[cur];
            if(val)
                update(1,1,n,cur,n,val);
            s[cur] = -1;
            cnt += val;
            //cout << "update : " << cur << ' ' << val << endl;
        }
        else
        {
            val = -s[cur];
            if(val)
                update(1,1,n,cur,n,val);
            s[cur] = 0;
            cnt += val;
            //cout << "update : " << cur << ' ' << val << endl;
        }
 
        push(1);
 
        //cout << tree[1].mn << ' ' << tree[1].mx << ' ' << cnt << endl;
 
        if(tree[1].mn < 0 || cnt)
            cout << -1 << ' ';
        else
            cout << tree[1].mx << ' ';
    }
 
    return 0;
}