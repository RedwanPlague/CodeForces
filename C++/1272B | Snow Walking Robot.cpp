#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int l, r, u, d;
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        l = 0; r = 0; u = 0; d = 0;
        for(char c : s)
        {
            switch(c)
            {
                case 'U': u++; break;
                case 'D': d++; break;
                case 'L': l++; break;
                case 'R': r++; break;
            }
        }
        int lr = min(l,r);
        int ud = min(u,d);
 
        if(!lr && ud)
        {
            cout << "2\nUD";
        }
        else if(!ud && lr)
        {
            cout << "2\nLR";
        }
        else
        {
            cout << 2*(lr+ud) << '\n';
            for(int i=0; i<lr; i++)
                cout << 'R';
            for(int i=0; i<ud; i++)
                cout << 'U';
            for(int i=0; i<lr; i++)
                cout << 'L';
            for(int i=0; i<ud; i++)
                cout << 'D';
        }
        cout << '\n';
    }
 
    return 0;
}