#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 65
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
string grid[MX];
int r, c;
 
int pcnt(int si, int sj, int ei, int ej)
{
    if(si < 0 || ei > r || sj < 0 || ej > c)
        return 0;
    int cnt = 0;
    for(int i=si; i<ei; i++)
    {
        for(int j=sj; j<ej; j++)
        {
            if(grid[i][j] == 'P')
                cnt++;
        }
    }
    return (cnt > 0);
}
 
int row(int i)
{
    int a = 0, p = 0;
    for(int j=0; j<c; j++)
    {
        if(grid[i][j] == 'P')
            p++;
        else
            a++;
    }
    if(a == c)
        return 0;
    if(p == c)
        return 100;
 
    if(grid[i][0] == 'A' || grid[i][c-1] == 'A')
        return 1;
    return 2;
}
 
int col(int j)
{
    int a = 0, p = 0;
    for(int i=0; i<r; i++)
    {
        if(grid[i][j] == 'P')
            p++;
        else
            a++;
    }
    if(a == r)
        return 0;
    if(p == r)
        return 100;
 
    if(grid[0][j] == 'A' || grid[r-1][j] == 'A')
        return 1;
    return 2;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
 
    while(T--)
    {
        cin >> r >> c;
        for(int i=0; i<r; i++)
            cin >> grid[i];
        int mn = 100;
        for(int i=0; i<r; i++)
        {
            int sc = row(i) + pcnt(0,0,i,c) + pcnt(i+1,0,r,c);
            mn = min(mn,sc);
        }
        for(int j=0; j<c; j++)
        {
            int sc = col(j) + pcnt(0,0,r,j) + pcnt(0,j+1,r,c);
            mn = min(mn,sc);
        }
        if(mn > 4)
            cout << "MORTAL\n";
        else
            cout << mn << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 