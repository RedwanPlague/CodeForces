#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 30
#define MOD 1000000007 DBL
 
int main()
{
    ios_base::sync_with_stdio(0); //cin.tie(0); cout.tie(0);
 
    int n, m;
    cin>>n>>m;
    string grid[n];
    for(int i=0; i<n; i++)
        cin>>grid[i];
 
    int bulb[2005];
 
    for(int j=0; j<m; j++)
    {
        bulb[j] = 0;
        for(int i=0; i<n; i++)
            bulb[j] += grid[i][j] - '0';
    }
 
    for(int i=0; i<n; i++)
    {
        bool on = true;
        for(int j=0; j<m; j++)
        {
            if(bulb[j] <= grid[i][j] - '0')
            {
                on = false;
                break;
            }
        }
        if(on)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
 
    cout<<"NO"<<endl;
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 