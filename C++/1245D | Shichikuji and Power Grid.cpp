#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 2005
#define x first
#define y second
 
struct Edge
{
    int u, v;
    ll w;
    Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &rhs) const
    {
        return (w < rhs.w);
    }
};
 
int par[MX], sz[MX];
 
void init()
{
    for(int i=0; i<MX; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
 
int findpar(int r)
{
    if(r == par[r])
        return r;
    return (par[r] = findpar(par[r]));
}
 
bool connected(int u, int v)
{
    return (findpar(u) == findpar(v));
}
 
void unite(int u, int v)
{
    int a = findpar(u);
    int b = findpar(v);
    if(a != b)
    {
        if(sz[a] > sz[b])
        {
            par[b] = a;
            sz[a] += sz[b];
        }
        else
        {
            par[a] = b;
            sz[b] += sz[a];
        }
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vector<pii> pnt(n);
    init();
    for(int i=0; i<n; i++)
    {
        cin >> pnt[i].x >> pnt[i].y;
    }
 
    vector<ll> c(n), k(n);
    for(int i=0; i<n; i++)
        cin >> c[i];
    for(int i=0; i<n; i++)
        cin >> k[i];
 
    vector<Edge> edge;
    for(int i=0; i<n; i++)
    {
        edge.emplace_back(i,n,c[i]);
        for(int j=i+1; j<n; j++)
            edge.emplace_back(i,j, (abs(pnt[i].x-pnt[j].x)+abs(pnt[i].y-pnt[j].y)) * (k[i]+k[j]) );
    }
 
    sort(edge.begin(),edge.end());
    ll cost = 0;
    vi city;
    vector<pii> con;
    for(auto &e: edge)
    {
        if(!connected(e.u,e.v))
        {
            cost += e.w;
            unite(e.u,e.v);
            if(e.v == n)
                city.push_back(e.u);
            else
                con.emplace_back(e.u,e.v);
        }
    }
    cout << cost << endl;
    cout << city.size() << endl;
    for(int x: city)
        cout << x+1 << ' ';
    cout << endl;
    cout << con.size() << endl;
    for(auto c: con)
        cout << c.x+1 << ' ' << c.y+1 << endl;
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 