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
 
struct Point
{
    ll x, y;
};
 
ll dist(const Point &a, const Point &b)
{
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    if(n&1)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<Point> pnt(n);
    for(int i=0; i<n; i++)
    {
        cin >> pnt[i].x >> pnt[i].y;
    }
    int m = n/2;
    for(int i=0, j=m; i<m; i++,j++)
    {
        if((pnt[i].y-pnt[i+1].y)*(pnt[j].x-pnt[(j+1)%n].x) != (pnt[i].x-pnt[i+1].x)*(pnt[j].y-pnt[(j+1)%n].y))
        {
            cout << "NO" << endl;
            return 0;
        }
        if(dist(pnt[i],pnt[i+1]) != dist(pnt[j],pnt[(j+1)%n]))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
 
    return 0;
}