#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
 
    cout << fixed << setprecision(10);
 
    while(t--)
    {
        int d;
        cin >> d;
        if(d*d >= 4*d)
        {
            double D = d*d - 4.0*d;
            double x = (d+sqrt(D))/2;
            double y = d - x;
            if(x >= 0 && y >= 0)
            {
                cout << "Y " << x << " " << y << "\n";
            }
            else
            {
                cout << "N\n";
            }
        }
        else
        {
            cout << "N\n";
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 