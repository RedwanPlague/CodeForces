#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n;
    cin >> n;
    ll ans = 3*(1LL<<((n<<1)-3)) + (n-3)*9*(1LL<<((n<<1)-6));
    cout << ans << endl;
    return 0;
}