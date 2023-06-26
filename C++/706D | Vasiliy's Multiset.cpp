#include <bits/stdc++.h>
 
using namespace std;
 
class Trie
{
    struct Node
    {
        int ar[2], cnt;
        Node()
        {
            ar[0] = ar[1] = -1;
            cnt = 0;
        }
    };
 
    vector<Node> v;
 
    int finish(int pos, int idx, int x)
    {
        if(pos < 0)
        {
            v[idx].cnt--;  // jehetu duplicate value allowed
            if(v[idx].cnt == 0)  // sob gula x sesh hoye gele
                return -1;
            return idx;
        }
        v[idx].ar[(x>>pos)&1] = finish(pos-1,v[idx].ar[(x>>pos)&1],x);
        //cout << idx << '(' << v[idx].ar[0] << ',' << v[idx].ar[1] << ')' << ' ';
        if(v[idx].ar[0] == -1 && v[idx].ar[1] == -1)  // eidike ar kono rasta na thakle
            return -1;
        return idx;
    }
 
public:
 
    Trie()
    {
        v.emplace_back();
    }
 
    void add(int x)
    {
        int idx = 0;
        for(int i=30; i>=0; i--)
        {
            int bit = (x>>i)&1;
            if(v[idx].ar[bit] == -1)  // rasta na thakle banay nibo
            {
                v[idx].ar[bit] = v.size();
                v.emplace_back();
            }
            //cout << idx << '(' << v[idx].ar[0] << ',' << v[idx].ar[1] << ')' << ' ';
            idx = v[idx].ar[bit];
        }
        //cout << idx << '(' << v[idx].ar[0] << ',' << v[idx].ar[1] << ')' << ' ';
        //cout << endl;
        v[idx].cnt++;
    }
 
    void extract(int x)
    {
        finish(30,0,x);
        //cout << endl;
    }
 
    int max_xor(int x)
    {
        int idx = 0;
        int ret = 0;
        for(int i=30; i>=0; i--)
        {
            //cout << idx << '(' << v[idx].ar[0] << ',' << v[idx].ar[1] << ')' << ' ';
            int bit = (x>>i)&1;
            if(v[idx].ar[bit^1] != -1)  // ulta bit er dike jawar chesta korbo xor er value baraite
            {
                idx = v[idx].ar[bit^1];
                ret |= (1<<i);
            }
            else  // na parle jei rasta ache oita diyei jawa lagbe
                idx = v[idx].ar[bit];
        }
        //cout << idx << '(' << v[idx].ar[0] << ',' << v[idx].ar[1] << ')' << ' ';
        //cout << endl;
        return ret;
    }
 
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    Trie trie;
    trie.add(0);
 
    int q, x;
    char ch;
 
    cin >> q;
    while(q--)
    {
        cin >> ch >> x;
        switch(ch)
        {
        case '+':
            trie.add(x);
            break;
        case '-':
            trie.extract(x);
            break;
        case '?':
            cout << trie.max_xor(x) << '\n';
        }
    }
 
    return 0;
}