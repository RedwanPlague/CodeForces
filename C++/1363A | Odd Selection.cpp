#include <iostream>
#include <cassert>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, a, even = 0, odd = 0;
        cin >> n >> x;
        assert(x <= n);
        for (int i=0; i<n; i++)
        {
            cin >> a;
            (a & 1) ? odd++ : even++;
        }
 
        if(!odd)
            cout << "No\n";
        else
        {
            x--;
            odd--;
 
            if (x&1)
            {
                if (!even)
                    cout << "No\n";
                else
                {
                    x--;
                    even--;
 
                    odd -= (odd & 1);
                    x -= min(x, odd);
 
                    if(x <= even)
                        cout << "Yes\n";
                    else
                        cout << "No\n";
                }
            }
            else
            {
                odd -= (odd & 1);
                x -= min(x, odd);
                
                if(x <= even)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }
 
    return 0;
}