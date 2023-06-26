#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    int anst = 1, cost = 100000000;
 
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    for(int t=1; t<=100; t++)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += max(0,abs(a[i]-t)-1);
        if(sum < cost)
        {
            cost = sum;
            anst = t;
        }
        //cout << sum << endl;
    }
 
    cout << anst << ' ' << cost << endl;
 
    return 0;
}