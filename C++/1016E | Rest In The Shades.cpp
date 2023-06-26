// https://codeforces.com/problemset/problem/1016/E
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
 
using namespace std;
 
#define all(v) (v).begin(),(v).end()
 
typedef vector<int> vi;
 
#define ceil(a,b) ( !(a) ? 0 : ((a)-1)/(b)+1 )
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    cout << fixed << setprecision(12);
 
    int sy, a, b;
    cin >> sy >> a >> b;
    int n, l, r;
    cin >> n;
    vi lim(2*n), len(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> l >> r;
        lim[2*i] = l;
        lim[2*i+1] = r;
        len[i+1] = len[i] + r-l;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        double scale = ((double)y-sy)/y;
        double cut1 = ((double)y * a - (double)sy * x) / (y - sy);
        double cut2 = ((double)y * b - (double)sy * x) / (y - sy);
        int use1 = ceil((long long)y * a - (long long)sy * x , y - sy);
        int use2 = ((long long)y * b - (long long)sy * x) / (y - sy);
        //cout << scale << ' ' << cut1 << ' ' << cut2 << ' ' << use1 << ' ' << use2 << '\n';
        int i = distance( lim.begin(), lower_bound(all(lim),use1) );
        int j = distance( lim.begin(), upper_bound(all(lim),use2) ) - 1;
 
        double shade = 0;
        if(j < i)
        {
            if((i&1) && (!(j&1)))
                shade += cut2 - cut1;
        }
        else 
        {
            if(i&1)
            {
                shade += lim[i] - cut1;
                i++;
            }
            if(!(j&1))
            {
                shade += cut2 - lim[j];
                j--;
            }
            if(j>i)
            {
                i /= 2;
                j /= 2;
                shade += len[j+1] - len[i];
            }
        }
 
        cout << shade * scale << '\n';
    }
 
    return 0;
}