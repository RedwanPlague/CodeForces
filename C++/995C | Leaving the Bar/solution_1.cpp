// https://codeforces.com/contest/995/problem/C
 
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
 
using namespace std;
 
#define F first
#define S second
 
typedef long long ll;
typedef vector<int> vi;
 
const ll LIM2 = 1'000'000'000'000;
 
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
    Point operator - () const
    {
        return Point(-x,-y);
    }
    Point operator * (ll c) const
    {
        return Point(x*c, y*c);
    }
    Point operator / (ll c) const
    {
        return Point(x/c, y/c);
    }
};
typedef Point Vector;
 
ll norm2(Point p)
{
    return p.x*p.x+p.y*p.y;
}
ostream &operator<<(ostream &os, const Point &p)
{
    return os << p.x << ' ' << p.y << endl;
}
istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
 
    vector<Vector> v(n);
    vector<int> sign(n,1);
    for(int i=0; i<n; i++)
        cin >> v[i];
 
    Vector &u1 = v[0], &u2 = v[1];
    vi l1 = {0}, l2 = {1};
    for(int k=2; k<n; k++)
    {
        Vector &u3 = v[k];
        if(norm2(u1+u3) <= LIM2)
        {
            u1 = u1+u3;
            l1.push_back(k);
        }
        else if(norm2(u1-u3) <= LIM2)
        {
            sign[k] = -sign[k];
            u1 = u1-u3;
            l1.push_back(k);
        }
        else if(norm2(u2+u3) <= LIM2)
        {
            u2 = u2+u3;
            l2.push_back(k);
        }
        else if(norm2(u2-u3) <= LIM2)
        {
            sign[k] = -sign[k];
            u2 = u2-u3;
            l2.push_back(k);
        }
        else if(norm2(u1+u2) <= LIM2)
        {
            if(l1.size() >= l2.size())
            {
                move(l2.begin(), l2.end(), std::back_inserter(l1));
                l2 = {k};
                u1 = u1+u2;
                u2 = u3;
            }
            else
            {
                move(l1.begin(), l1.end(), std::back_inserter(l2));
                l1 = {k};
                u2 = u1+u2;
                u1 = u3;
            }
        }
        else if(norm2(u1-u2) <= LIM2)
        {
            if(l1.size() >= l2.size())
            {
                for(auto x: l2)
                    sign[x] = -sign[x];
                move(l2.begin(), l2.end(), std::back_inserter(l1));
                l2 = {k};
                u1 = u1-u2;
                u2 = u3;
            }
            else
            {
                for(auto x: l1)
                    sign[x] = -sign[x];
                move(l1.begin(), l1.end(), std::back_inserter(l2));
                l1 = {k};
                u2 = u2-u1;
                u1 = u3;
            }
        }
    }
    
    if(norm2(u1-u2) <= 2*LIM2) // it should be 2*LIM2 not LIM2, i don't know how the previous submission got AC :3
    {
        if(l1.size() >= l2.size())
        {
            for(auto x: l2)
                sign[x] = -sign[x];
        }
        else
        {
            for(auto x: l1)
                sign[x] = -sign[x];
        }
    }
 
    for(auto x: sign)
        cout << x << ' ';
    cout << endl;
 
    return 0;
}