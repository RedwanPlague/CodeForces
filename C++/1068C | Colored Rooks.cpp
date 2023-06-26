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
 
    int n, m;
    cin >> n >> m;
    vector <vi> points(n+1);
    int a, b;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        points[a].push_back(1000*a+b);
        points[b].push_back(1000*a+b);
    }
 
    for(int i=1; i<=n; i++)
    {
        cout << max(1,(int)points[i].size()) << '\n';
        for(int j=0; j<points[i].size(); j++)
            cout << i << ' ' << points[i][j] << '\n';
        if(points[i].size() == 0)
        {
            cout << i << ' ' << i << '\n';
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 