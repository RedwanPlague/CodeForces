// https://codeforces.com/problemset/problem/630/O
 
#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double INF = 1e100;
double EPS = 1e-12;
 
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
    Point operator - () const
    {
        return Point(-x,-y);
    }
    Point operator * (double c) const
    {
        return Point(x*c, y*c);
    }
    Point operator / (double c) const
    {
        return Point(x/c, y/c);
    }
};
typedef Point Vector;
 
double dot(Point p, Point q)
{
    return p.x*q.x+p.y*q.y;
}
ostream &operator<<(ostream &os, const Point &p)
{
    return os << p.x << ' ' << p.y << endl;
}
istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}
 
// rotate a point CCW or CW around the origin
Point RotateCCW90(Point p)
{
    return Point(-p.y,p.x);
}
Point RotateCW90(Point p)
{
    return Point(p.y,-p.x);
}
 
int main()
{
    Point p;
    Vector v;
    double a, b, c, d;
    cin >> p >> v >> a >> b >> c >> d;
 
    Vector up = v / sqrt(dot(v,v)); // unit vector in the direction of v 
    Vector left = RotateCCW90(up);
    Vector right = RotateCW90(up);
    Vector down = -up;
 
    Point A = p + up * b;
    Point B = p + left * a/2;
    Point C = p + left * c/2;
    Point G = p + right * a/2;
    Point F = p + right * c/2;
    Point D = C + down * d;
    Point E = F + down * d;
 
    cout << fixed << setprecision(12);
    cout << A << B << C << D << E << F << G;
 
    return 0;
}