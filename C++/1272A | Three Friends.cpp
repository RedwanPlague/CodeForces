#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        cout << max(0,2*(a[2]-a[0]-2)) << '\n';
    }
 
    return 0;
}