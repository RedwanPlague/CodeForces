#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int W, H, n, pos, l, r;
    char ch;
    cin >> W >> H >> n;
 
    set<int> x, y;
    multiset<ll> w, h;
 
    x.insert(0);
    x.insert(W);
    y.insert(0);
    y.insert(H);
 
    w.insert(W);
    h.insert(H);
 
    set<int> :: iterator ir, il;
    multiset<ll> :: iterator imw, imh, idx;
 
    while(n--)
    {
        cin >> ch >> pos;
        if(ch == 'H')
        {
            ir = y.upper_bound(pos);
            il = ir;
            il--;
            int prev = *ir - *il;
            idx = h.find(prev);
            h.erase(idx);
            h.insert(*ir-pos);
            h.insert(pos-*il);
            y.insert(pos);
        }
        else
        {
            ir = x.upper_bound(pos);
            il = ir;
            il--;
            int prev = *ir - *il;
            idx = w.find(prev);
            w.erase(idx);
            w.insert(*ir-pos);
            w.insert(pos-*il);
            x.insert(pos);
        }
        imw = w.end();
        imw--;
        imh = h.end();
        imh--;
        cout << (*imw)*(*imh) << '\n';
    }
 
    return 0;
}