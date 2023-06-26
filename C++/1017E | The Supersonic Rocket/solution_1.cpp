// https://codeforces.com/problemset/problem/1017/E
 
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
 
using namespace std;
 
#define all(v) (v).begin(),(v).end()
 
const double INF = 1e100;
const double EPS = 1e-12;
const double PI = acos(-1);
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
#define F first
#define S second
 
struct Point
{
    ll x, y;
 
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
 
    Point operator + (const Point &p) const
    {
        return Point(x+p.x, y+p.y);
    }
    Point operator - (const Point &p) const
    {
        return Point(x-p.x, y-p.y);
    }
    bool operator < (const Point &rhs) const
    {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
};
 
ll dot(Point p, Point q)
{
    return p.x*q.x+p.y*q.y;
}
ll dist2(Point p, Point q)
{
    return dot(p-q,p-q);
}
ll angle(Point a, Point b, Point c)
{
    return dot(a-b,c-b);
}
ll cross(Point p, Point q)
{
    return p.x*q.y-p.y*q.x;
}
ll area2(Point a, Point b, Point c)
{
    return cross(a,b) + cross(b,c) + cross(c,a);
}
 
ostream &operator<<(ostream &os, const Point &p)
{
    return os << "(" << p.x << "," << p.y << ")";
}
istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}
 
bool between(const Point &a, const Point &b, const Point &c)
{
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
 
void ConvexHull(vector<Point> &pts)
{
    sort(pts.begin(), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++)
    {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0)
            up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0)
            dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--)
        pts.push_back(up[i]);
 
    if (pts.size() <= 2)
        return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++)
    {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i]))
            dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
}
 
bool kmp(const vector<pll> &s, int len) 
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) 
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        
        if(j == len)
            return true;
        pi[i] = j;
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<Point> s1(n), s2(m);
    for(int i=0; i<n; i++)
        cin >> s1[i];
    for(int i=0; i<m; i++)
        cin >> s2[i];
 
    ConvexHull(s1);
    ConvexHull(s2);
    n = s1.size();
    m = s2.size();
 
    vector<pll> h1(n), h2(m);
    for(int i=0; i<n; i++)
    {
        h1[i].F = dist2(s1[i], s1[i+1 == n ? 0 : i+1]);
        h1[i].S = angle(s1[i==0 ? n-1 : i-1], s1[i], s1[i+1 == n ? 0 : i+1]);
        // cout << h1[i].F << ' ' << h1[i].S/PI*180 << endl;
    }
    for(int i=0; i<m; i++)
    {
        h2[i].F = dist2(s2[i], s2[i+1 == n ? 0 : i+1]);
        h2[i].S = angle(s2[i==0 ? n-1 : i-1], s2[i], s2[i+1 == n ? 0 : i+1]);
        // cout << h2[i].F << ' ' << h2[i].S/PI*180 << endl;
    }
 
    h2.emplace_back(-1,-1);
    h2.insert(h2.end(),all(h1));
    h2.insert(h2.end(),all(h1));
 
    if(kmp(h2,m))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}