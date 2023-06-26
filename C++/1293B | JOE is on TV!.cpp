#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) (v).begin(),(v).end()
 
int main()
{
    int n;
    while(cin >> n)
    {
        double sum = 0;
        for(double i=1; i<=n; i++)
        {
            sum += 1/i;
        }
        cout << fixed << setprecision(10) << sum << endl;
    }
    
    return 0;
}