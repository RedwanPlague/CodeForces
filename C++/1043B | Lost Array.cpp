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
    cin >> n;
    vi b(n), a(n);
    for(int i=0; i<n; i++)
        cin >> b[i];
    a[0] = b[0];
    for(int i=1; i<n; i++)
        a[i] = b[i] - b[i-1];
 
    vi ans;
 
    for(int len = 1; len < n; len++)
    {
        bool mark = true;
        for(int idx = len, add = 0; idx < n; idx++)
        {
            if(idx % len == 0)
                add += len;
            if(a[idx] != a[idx-add])
            {
                mark = false;
                break;
            }
        }
        if(mark)
            ans.push_back(len);
    }
 
    ans.push_back(n);
 
    cout << ans.size() <<endl;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 