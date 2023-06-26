#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
struct perm
{
    int a, b, c;
 
    bool contains(int x)
    {
        return (a == x || b == x || c == x);
    }
};
 
perm except(vector<perm> &v, vi &li, int ex)
{
    for(int i=0; i<li.size(); i++)
    {
        if(!v[li[i]].contains(ex))
            return v[li[i]];
    }
}
 
int cont(vector<perm> &v, vector<vi> &li, int cur, int he, perm p)
{
    if(p.a != cur && p.a != he)
    {
        for(int i=0; i<li[p.a].size(); i++)
        {
            if(v[li[p.a][i]].contains(he))
                return p.a;
        }
    }
 
    if(p.b != cur && p.b != he)
    {
        for(int i=0; i<li[p.b].size(); i++)
        {
            if(v[li[p.b][i]].contains(he))
                return p.b;
        }
    }
 
    return p.c;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vector<perm> v(n-2);
    vector<vi> li(n+1);
    for(int i=0; i<n-2; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].c;
        li[v[i].a].push_back(i);
        li[v[i].b].push_back(i);
        li[v[i].c].push_back(i);
    }
 
    int start;
    for(int i=1; i<=n; i++)
    {
        if(li[i].size() == 1)
        {
            start = i;
            break;
        }
    }
 
    vi ans(n);
    int ia = 0;
    ans[ia++] = start;
    int prev = start;
 
    int b, c;
 
    if(v[li[start][0]].a == start)
    {
        b = v[li[start][0]].b;
        c = v[li[start][0]].c;
    }
    else if(v[li[start][0]].b == start)
    {
        b = v[li[start][0]].a;
        c = v[li[start][0]].c;
    }
    else
    {
        b = v[li[start][0]].a;
        c = v[li[start][0]].b;
    }
 
    //cout << b << ' ' << c << endl;
 
    int cur = (li[b].size() == 2) ? b : c;
 
    //cout << cur << endl;
 
    while(ia < n)
    {
        ans[ia++] = cur;
 
        if(ia == n)
            break;
 
        perm next = except(v,li[cur],prev);
        int temp = cont(v,li,cur,prev,next);
        prev = cur;
        cur = temp;
    }
 
    for(int i=0; i<n; i++)
        cout << ans[i] << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 