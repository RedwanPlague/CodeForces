#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int n;
    string s;
    cin >> n >> s;
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] != s[i-1])
        {
            cout << "YES\n";
            cout << s[i-1] << s[i] << endl;
            return 0;
        }
    }
    cout << "NO\n";
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 