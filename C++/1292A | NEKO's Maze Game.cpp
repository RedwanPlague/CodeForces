#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int q, n;
    cin >> n >> q;
    vector<vb> road(2,vb(n,false));
    set<int> col, cell[2];
 
    int r, c, nr;
    while(q--)
    {
        cin >> r >> c;
        r--; c--;
        nr = 1-r; // other row 
        if(!road[r][c])
        {
            road[r][c] = true;
            if(road[nr][c])
                col.insert(c);
            if(c && road[nr][c-1])
                cell[r].insert(c-1);
            if(c+1<n && road[nr][c+1])
                cell[nr].insert(c);
        }
        else 
        {
            road[r][c] = false;
            col.erase(c);
            if(c)
                cell[r].erase(c-1);
            if(c+1<n)
                cell[nr].erase(c);
        }
 
        /*cout << "blocked cols: ";
        for(int x: col)
            cout << x+1 << ' ';
        cout << "\nblocked cells:\n\trow1: ";
        for(int x: cell[0])
            cout << x+1 << ' ';
        cout << "\n\trow2: ";
        for(int x: cell[1])
            cout << x+1 << ' ';
        cout << endl;*/
 
        if(col.size() || cell[0].size() || cell[1].size())
            cout << "NO\n";
        else 
            cout << "YES\n";
        //cout << endl;
    }
 
    return 0;
}