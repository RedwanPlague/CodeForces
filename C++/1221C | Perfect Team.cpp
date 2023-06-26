#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int Q;
    cin >> Q;
    while(Q--)
    {
        int m, c, x;
        cin >> c >> m >> x;
        if(m < c)
            swap(c,m);
 
        int ans;
        if(c <= x)
            ans = c;
        else
        {
            if(x+m >= 2*c)
                ans = c;
            else
            {
                ans = x;
                c -= x;
                m -= x;
                ans += (c+m)/3;
            }
        }
        cout << ans << '\n';
    }
 
    return 0;
}