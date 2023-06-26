#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> cnt(30,0);
        int a, pw;
        for(int i=0; i<n; i++)
        {
            cin >> a;
            pw = 0;
            while(a > 1)
            {
                pw++;
                a >>= 1;
            }
            cnt[pw]++;
        }
        for(int i=0; i<11; i++)
        {
            cnt[i+1] += cnt[i]/2;
        }
        if(cnt[11])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
 
    return 0;
}