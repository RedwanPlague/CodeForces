#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int mx = 1005;
const int MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, a, b;
 
    cin>>n>>a>>b;
 
    if(n == 1 && a == 1 && b == 1)
    {
        cout<<"YES"<<'\n';
        cout<<"0"<<endl;
        return 0;
    }
 
    if((a != 1 && b != 1) || (a == 1 && b == 1 && n <= 3))
    {
        cout<<"NO"<<endl;
        return 0;
    }
 
    cout<<"YES"<<'\n';
 
    bool grid[mx][mx];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            grid[i][j] = 0;
        }
    }
 
    if(a == 1 && b == 1)
    {
        for(int i=1; i<n; i++)
        {
            grid[i][i-1] = grid[i-1][i] = 1;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<grid[i][j];
            }
            cout<<'\n';
        }
        return 0;
    }
 
    int comp = (a+b)-1;
 
    int each = (n/comp);
    int cur = 0;
 
    for(int cnt=1; cnt<comp; cnt++)
    {
        vector <int> v;
        for(int u = cur; u < cur + each; u++)
            v.push_back(u);
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                grid[v[i]][v[j]] = grid[v[j]][v[i]] = 1;
            }
        }
        cur += each;
    }
 
    vector <int> v;
    for(int u = cur; u < n; u++)
        v.push_back(u);
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            grid[v[i]][v[j]] = grid[v[j]][v[i]] = 1;
        }
    }
 
    bool flip = 0;
    if(a == 1)
        flip = 1;
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j)
                cout<<"0";
            else
                cout<<(grid[i][j]^flip);
        }
        cout<<'\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 