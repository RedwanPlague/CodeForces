// https://codeforces.com/problemset/problem/605/C
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
 
using namespace std;
 
double INF = 1e100;
double EPS = 1e-12;
#define REMOVE_REDUNDANT
 
struct Point
{
    double x, y;
 
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
 
    Point operator + (const Point &p) const
    {
        return Point(x+p.x, y+p.y);
    }
    Point operator - (const Point &p) const
    {
        return Point(x-p.x, y-p.y);
    }
    Point operator * (double c) const
    {
        return Point(x*c, y*c);
    }
    Point operator / (double c) const
    {
        return Point(x/c, y/c);
    }
    bool operator < (const Point &rhs) const
    {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator == (const Point &rhs) const
    {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};
typedef Point Vector;
 
double dot(Point p, Point q)
{
    return p.x*q.x+p.y*q.y;
}
double norm(Point p) 
{
    return sqrt(p.x*p.x+p.y*p.y);
}
double dist2(Point p, Point q)
{
    return dot(p-q,p-q);
}
double cross(Point p, Point q)
{
    return p.x*q.y-p.y*q.x;
}
double area2(Point a, Point b, Point c)
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
 
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(Point a, Point b, Point c, Point d)
{
    return fabs(cross(b-a, c-d)) < EPS;
}
 
bool LinesCollinear(Point a, Point b, Point c, Point d)
{
    return LinesParallel(a, b, c, d) // this parallel check not needed, the other two suffice
           && fabs(cross(a-b, a-c)) < EPS
           && fabs(cross(c-d, c-a)) < EPS;
}
 
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(Point a, Point b, Point c, Point d)
{
    if (LinesCollinear(a, b, c, d))
    {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS)
            return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
    }
    if (cross(d-a, b-a) * cross(c-a, b-a) > 0)
        return false;
    if (cross(a-c, d-c) * cross(b-c, d-c) > 0)
        return false;
    return true;
}
 
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
Point ComputeLineIntersection(Point a, Point b, Point c, Point d)
{
    b=b-a;
    d=c-d;
    c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}
 
#ifdef REMOVE_REDUNDANT
bool between(const Point &a, const Point &b, const Point &c)
{
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif
 
void ConvexHull(vector<Point> &pts)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
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
 
#ifdef REMOVE_REDUNDANT
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
#endif
}
 
int main()
{
    int n;
    double p, q;
    cin >> n >> p >> q;
    vector<Vector> v(n);
    double max_x = 0, max_y = 0;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        max_x = max(max_x, v[i].x);
        max_y = max(max_y, v[i].y);
    }
    v.emplace_back(max_x,0); // why add these two Vectors? explained later. 
    v.emplace_back(0,max_y); 
 
    // A 'convex combination' of Vectors is a linear combination of Vectors such that 
    // each co-efficient is non-negative and
    // sum of all coeff = 1 
    // The convex hull of a set of Vectors is all the points that can be derived by any of their convex combinations
    ConvexHull(v);
    // Now that we have the convex hull, all points inside it can be made from the given Vectors.
    // But we need to make the Vector (p,q), so we find the longest Vector inside our convex hull
    // that is parallel to (p,q) and scale it ||(p,q)||/||found vector|| times to get (p,q)
    // We take 'Longest Vector' so that scaling is minimum
    // Since in this problem 'time spent' is doing the scaling, 
    // the amount of scaling needed is the amount of time spent
 
    // Aah, yes, those two extra Vectors. 
    // We don't need to make (p,q) exactly. Atleast p and atleast q. 
    // Vector (max_x,0) only adds to x, disregarding the addition to y, 
    // so if we need to make more than q, those extra y's will just become 0 by using (max_x,0)
    // and now we can only worry about making (p,q) exactly. 
    // we could insert (v[i].x,0) for all i, but since we will only need the longest Vector, what's the point. 
    // Same reasoning on (0,max_y)
 
    // Okay, so now we take a Vector in the direction of (p,q) and intersect it with the sides of the convex hull
    // there can be atmost two intersection points. one the shortest, the other longest.
 
    Point O(0,0), A(p,q);
    double la = norm(A);
 
    // I don't have a Segment-Line intersection function
    // so just shifting point (p,q) far enough 
    // to make (0,0)-(p,q) Segment work like a Line
    A = A / la * 2e6;
 
    double min_scale = INF;
    for(int i=0, j=1; i<v.size(); i++, j=(j+1)%v.size()) 
    {
        if(LinesCollinear(O,A,v[i],v[j]))
        {
            min_scale = min(min_scale, la/norm(v[i]));
            min_scale = min(min_scale, la/norm(v[j]));
        }
        else if(SegmentsIntersect(O,A,v[i],v[j]))
        {
            Point sect = ComputeLineIntersection(O,A,v[i],v[j]);
            min_scale = min(min_scale, la/norm(sect));
        }
    }
 
    cout << fixed << setprecision(12);
    cout << min_scale << endl;
 
    return 0;
}