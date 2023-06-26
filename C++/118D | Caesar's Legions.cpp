#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
#define MOD 100000000
 
ll dp[101][101][11][11];
int vis[101][101][11][11], mark;
int N1, N2, K1, K2;
 
// n1 = footmen left
// n2 = horsemen left
// k1 footmen can still be kept successively 
// k2 horsemen can still be kept successively 
ll ways(int n1, int n2, int k1, int k2)
{
    ll &dpcur = dp[n1][n2][k1][k2];
    int &viscur = vis[n1][n2][k1][k2];
 
    if(viscur == mark)
        return dpcur;
 
    viscur = mark;
 
    if(n1 == 0)
    {
        return ( dpcur = (n2 <= k2)%MOD ); // if no footmen left, all horsemen must stand successively 
    }
    if(n2 == 0)
    {
        return ( dpcur = (n1 <= k1)%MOD ); // same logic
    }
 
    dpcur = 0;
    if(k1)
        dpcur = (dpcur + ways(n1-1,n2,k1-1,K2))%MOD;
    if(k2)
        dpcur = (dpcur + ways(n1,n2-1,K1,k2-1))%MOD;
    
    return dpcur;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    while(cin >> N1 >> N2 >> K1 >> K2)
    {
        mark++;
        cout << ways(N1,N2,K1,K2) << endl;
    }
}