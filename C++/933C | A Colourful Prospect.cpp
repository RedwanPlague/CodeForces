#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
#define read(n) scanf("%d", &n)
#define read2(a,b) scanf("%d %d", &a, &b)
#define all(v) (v).begin(),(v).end()
 
#define EPS 1e-10
 
typedef long long ll;
 
struct Pointd
{
    long double x, y;
 
    Pointd() {}
    Pointd(long double x, long double y) : x(x), y(y) {}
 
    bool operator==(const Pointd& obj) const
    {
        return (fabs(x-obj.x)<=EPS && fabs(y-obj.y)<=EPS);
    }
 
    bool operator<(const Pointd& obj) const
    {
        if(fabs(x-obj.x)<=EPS)
            return (y<obj.y);
        return (x<obj.x);
    }
};
 
struct Point
{
    ll x, y;
 
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
 
    void print() const
    {
        printf("(%2lld, %2lld)\n", x,y);
    }
 
    Point operator-(const Point& obj) const
    {
        return Point(x-obj.x,y-obj.y);
    }
 
    ll dot(const Point& obj) const
    {
        return (x*obj.x + y*obj.y);
    }
 
    ll norm2() const
    {
        return (x*x+y*y);
    }
};
 
struct Circle
{
    Point o;
    ll r;
 
    Circle() {}
    Circle(const Point& o, ll r) : o(o), r(r) {}
 
    void print() const
    {
        printf("(%2lld,%2lld,%2lld) ", o.x,o.y,r);
    }
 
    bool operator<(const Circle& obj) const
    {
        if(r == obj.r)
        {
            if(o.x == obj.o.x)
                return (o.y < obj.o.y);
            return (o.x < obj.o.x);
        }
        return (r < obj.r);
    }
};
 
int intersect(const Circle& c1, const Circle& c2, Pointd &p1, Pointd &p2)
{
    ll d2 = (c1.o-c2.o).norm2();
    long double d = sqrt(d2);
 
    ll temp1 = c1.r*c1.r+c2.r*c2.r;
    ll temp2 = 2*c1.r*c2.r;
 
    if( (temp1+temp2 < d2) || d2 < (temp1-temp2) )
    {
        return 0;
    }
 
    long double a = (c1.r*c1.r - c2.r*c2.r + d2)/(2*d);
 
    long double h = sqrt(c1.r*c1.r - a*a);
 
    Pointd pmid;
    pmid.x = c1.o.x + a*(c2.o.x-c1.o.x)/d;
    pmid.y = c1.o.y + a*(c2.o.y-c1.o.y)/d;
 
    if( (temp1+temp2 == d2) || (temp1-temp2 == d2) )
    {
        p1 = pmid;
        return 1;
    }
 
    p1.x = pmid.x + h*(c1.o.y-c2.o.y)/d;
    p1.y = pmid.y - h*(c1.o.x-c2.o.x)/d;
 
    p2.x = pmid.x - h*(c1.o.y-c2.o.y)/d;
    p2.y = pmid.y + h*(c1.o.x-c2.o.x)/d;
 
    return 2;
}
 
int par[505];
 
void dsu_init()
{
    for(int i=0; i<505; i++)
        par[i] = i;
}
 
int find_par(int r)
{
    if(r == par[r])
        return par[r];
    return (par[r] = find_par(par[r]));
}
 
void unite(int a, int b)
{
    int u = find_par(a);
    int v = find_par(b);
    if(u != v)
        par[u] = v;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
 
    dsu_init();
 
    int n;
    read(n);
    vector<Pointd> nodes;
    set<Circle> tcir;
 
    int x, y, r;
 
    for(int i=0; i<n; i++)
    {
        read2(x,y); read(r);
        tcir.insert(Circle(Point(x,y),r));
    }
 
    vector<Circle> circ;
    for(const Circle& x: tcir)
    {
        circ.push_back(x);
        //circ.back().print();
    }
 
    n = circ.size();
    vector< vector<Pointd> > edge_list(n);
 
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            Pointd p1, p2;
            int check = intersect(circ[i],circ[j],p1,p2);
            /*circ[i].print();
            circ[j].print();*/
 
            if(check == 1)
            {
                edge_list[i].push_back(p1);
                edge_list[j].push_back(p1);
 
                nodes.push_back(p1);
 
                unite(i,j);
 
                /*printf("~ 1    ");*/
                //printf("(%.10Lf,%.10Lf)", p1.x, p1.y);
            }
            else if(check == 2)
            {
                edge_list[i].push_back(p1);
                edge_list[j].push_back(p1);
 
                edge_list[i].push_back(p2);
                edge_list[j].push_back(p2);
 
                nodes.push_back(p1);
                nodes.push_back(p2);
 
                unite(i,j);
 
                /*printf("~ 2    ");*/
                //printf("(%.10Lf,%.10Lf) (%.10Lf,%.10Lf)", p1.x, p1.y, p2.x, p2.y);
            }
            //putchar('\n');
 
            /*for(int i=0; i<n; i++)
            {
                printf("%d ", edge[i]);
            }
            puts("");*/
        }
    }
 
    vector<Pointd>::iterator it;
 
    for(int i=0; i<n; i++)
    {
        sort(all(edge_list[i]));
        it = unique(all(edge_list[i]));
        edge_list[i].resize(distance(edge_list[i].begin(),it));
    }
    sort(all(nodes));
    it = unique(all(nodes));
    nodes.resize(distance(nodes.begin(),it));
 
    /*for(Pointd p: nodes)
    {
        printf("(%.10f, %.10f)\n", p.x, p.y);
    }*/
 
    int e = 0;
    int v = nodes.size();
    for(int i=0; i<n; i++)
    {
        e += edge_list[i].size();
        /*for(auto &p: edge_list[i])
            printf("(%.20Lf, %.20Lf)\n", p.x, p.y);
        puts("\n");*/
        //printf("%d ", edge[i]);
    }
    //puts("");
 
    set<int> temp;
    for(int i=0; i<n; i++)
    {
        temp.insert(find_par(i));
        //printf("%d ", find_par(i));
    }
    int c = temp.size();
 
    //printf("\n%d - %d + %d + 1\n", e, v, c);
 
    int face = e-v+c+1;
 
    printf("%d\n", face);
 
    return 0;
}