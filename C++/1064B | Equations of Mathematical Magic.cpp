#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 105;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        int cnt = 0;
        for(int pos=0; pos <= 30; pos++)
            if(a&(1<<pos))
                cnt++;
        cout << (1<<cnt) << br;
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 