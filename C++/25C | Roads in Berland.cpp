#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int MX = 301;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll dist[MX][MX];
    int n, k, u, v;
    ll w;
    cin >> n;
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> dist[i][j];
 
    cin >> k;
    while(k--)
    {
        cin >> u >> v >> w;
        u--; v--;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][u]+w+dist[v][j]), dist[i][j] = min(dist[i][j], dist[i][v]+w+dist[u][j]);
 
        ll sum = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                sum += dist[i][j];
 
        cout << sum << " ";
    }
    cout << endl;
 
    return 0;
}