#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 30;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin>>n;
    if(n%3 == 0)
    {
        cout << 1  << ' ' << 1 << ' ' << n-2 << endl;
        return 0;
    }
 
    cout << 1 << ' ' << 2  << ' ' << n-3 << endl;
 
    return 0;
}