#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
 
struct Pair
{
    int val, use, idx;
    Pair() {}
    bool operator<(const Pair &obj)
    {
        if(val == obj.val)
            return (use > obj.use);
        return (val < obj.val);
    }
};
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<Pair> edge(m);
    for(int i=0; i<m; i++)
    {
        cin >> edge[i].val >> edge[i].use;
        edge[i].idx = i;
    }
 
    sort(edge.begin(), edge.end());
 
    vi next(n+1,-1);
    int cur_use = 3;
    vector<pii> ans(m);
 
    next[1] = 2;
    for(int i=0; i<m; i++)
    {
        //cout << edge[i].val << " " << edge[i].use << "\n";
        if(edge[i].use)
        {
            ans[edge[i].idx].F = 1;
            next[next[1]] = next[1]-1;
            ans[edge[i].idx].S = next[1]++;
        }
        else
        {
            //cout << "; " << cur_use << " " << next[cur_use] << " ;\n";
            if(next[cur_use] == -1 || next[cur_use] == 1)
            {
                cout << -1 << endl;
                return 0;
            }
            ans[edge[i].idx].F = cur_use;
            ans[edge[i].idx].S = next[cur_use]--;
            if(next[cur_use] == 1)
                cur_use++;
        }
    }
 
    for(int i=0; i<m; i++)
        cout << ans[i].F << " " << ans[i].S << "\n";
 
    return 0;
}