#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
#define x first
#define y second
 
const ll range = 2e16+100;
 
int inbetween(int i, int j, int k)
{
    //cout << i << ' ' << j << ' ' << k << endl;
    return max(i,max(j,k)) - min(i,min(j,k)) + 1;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    while(cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t)
    {
        vector<pll> p; // to hold all reachable points
        ll xn = x0, yn = y0;
        while(xn < range && yn < range) 
        {
            p.emplace_back(xn,yn);
            xn = ax*xn + bx;
            yn = ay*yn + by;
        }
 
        int mx_data = 0;
        for(int i=0; i<p.size(); i++)
        {
            for(int j=0; j<p.size(); j++)
            {
                for(int k=0; k<p.size(); k++)
                {
                    ll time = abs(p[i].x - xs) + abs(p[i].y - ys) + abs(p[j].x - p[i].x) + abs(p[j].y - p[i].y) + abs(p[k].x - p[j].x) + abs(p[k].y - p[j].y);
                    if(time <= t)
                        mx_data = max(mx_data, inbetween(i,j,k));
                }
            }
        }
 
        cout << mx_data << endl;
    }
 
    return 0;
}