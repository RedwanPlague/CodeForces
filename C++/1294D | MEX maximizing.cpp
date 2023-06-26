#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> pii;
 
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int q, x, y, c;
    cin >> q >> x;
    vector<int> cnt(x,0);
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    for(int i=0; i<x; i++)
        pq.push({0,i});
    for(int i=0; i<q; i++)
    {
        cin >> y;
        y %= x;
        cnt[y]++;
        pq.push({cnt[y],y});
        while(pq.top().F < cnt[pq.top().S])
            pq.pop();
        cout << pq.top().F*x + pq.top().S << '\n';
    }
    
    return 0;
}