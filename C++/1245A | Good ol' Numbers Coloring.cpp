#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    int a, b;
    while(T--)
    {
        cin >> a >> b;
        if(__gcd(a,b) > 1)
            cout << "Infinite" << endl;
        else
            cout << "Finite" << endl;
    }
 
    return 0;
}