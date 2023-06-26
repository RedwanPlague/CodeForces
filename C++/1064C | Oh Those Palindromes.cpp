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
 
    int cnt[30];
    fill(cnt, cnt+30, 0);
    string s;
    int n;
    cin >> n;
    cin >> s;
 
    for(int i=0; i<n; i++)
    {
        cnt[s[i]-'a']++;
    }
    for(int i=0; i<30; i++)
    {
        while(cnt[i])
        {
            cout << (char)('a'+i);
            cnt[i]--;
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 