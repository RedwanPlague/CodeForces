/*
Problem Link: https://codeforces.com/problemset/problem/351/D
 
MO's Algo:
 
if there is a number that forms an arithmetic progression at the beginning, we remove that number on the first move,
since after the first move we can permute the numbers, we just sort the numbers and remove each equal group in one move.
thus ans = number of distinct numbers in [L,R]
but if no arithmetic progression is found the first move is kind of wasted.
so ans = number of distinct numbers in [L,R] + 1
example:
[1,2,2,1,1] -> the 2's form an arth. prg. so, remove the 2's then remove the 1's -> ans = 2
[1,2,1,1,2,2] -> no number forms any arth. prg. so, removing any sequence will still leave us with the same amount of distinct numbers
(we can't remove all the 2's or all the 1's in one move) so ans = 1(first move wasted) + 2 = 3
 
we keep an array that keeps track of distinct elements in [L,R], when adding new element if a[idx] = 0 we increase the count of distinct
elements, and if after a[idx]--, a[idx] = 0, we decrease the count of distinct elements
 
we precalculate array prg, where prg[i] = length of longest arithmetic progression that begins at position i.
i.e: ar = [1,2,3,2,4,2,5,4,2] -> here prg[1] = 3, as ar[1] = ar[3] = ar[5] so, 1,3,5 = len 3
 
we also keep deques for each number from 1 to 10^5
 
for [L-1,R], we check if any new distinct element has been added, and if any new arth.prg has been added or removed
for [L,R+1], same -> see code for more
for [L+1,R], .......
for [L,R-1], ......
*/
 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
 
using namespace std;
 
#define MX 100005
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define read(n) scanf("%d", &n)
#define read2(a,b) scanf("%d %d", &a, &b)
#define read3(a,b,c) scanf("%d %d %d", &a, &b, &c)
 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
 
struct Query
{
    int l, r, id;
};
 
class MO
{
    int cnt_arth;   // count of how many elements in [L,R] form arth.prg
    int distinct;   // count of distinct elements in [L,R]
    vi cnt, prg;
    vector< deque<int> > it;    // it[n] will keep index i's such that L <= i <= R and ar[i] = n
 
    bool is_arth_prg(int num) const
    {
        if(it[num].empty())
            return false;
        return (it[num].size() <= prg[it[num][0]]);
    }
 
public:
 
    MO(vi &ar)
    {
        cnt_arth = 0;
        distinct = 0;
        cnt.assign(MX,0);
        prg.resize(MX);
        it.resize(MX);
        vector<vi> idx(MX);     // idx[n] will keep the list of all index i's such that a[i] = n
 
        for(int i=0; i<ar.size(); i++)
        {
            idx[ar[i]].push_back(i);
        }
        for(int i=0; i<MX; i++)
        {
            if(idx[i].empty())
                continue;
            prg[idx[i].back()] = 1;
            int d = -1;
            for(int j=idx[i].size()-2; j>=0; j--)   // iterate over the other indexes where i has appeared in reverse order
            {
                if(idx[i][j+1] - idx[i][j] != d)
                {
                    prg[idx[i][j]] = 2;     // new arth.prg containing idx[i][j] and idx[i][j+1]
                    d = idx[i][j+1] - idx[i][j]; // new diff
                }
                else
                    prg[idx[i][j]] = prg[idx[i][j+1]] + 1; // extend previous arth.prg
            }
//            printf("%d = ", i);
//            for(int j=0; j<idx[i].size(); j++)
//                printf("%d ", prg[idx[i][j]]);
//            puts("");
        }
    }
 
    void add(int num, int idx, bool pole)
    {
        if(!cnt[num]) // cnt[num] = 0 means a new distinct number has been added
            distinct++;
        cnt[num]++;
        bool bef = is_arth_prg(num);    // if arth.prg of num already exists
 
        if(pole)
            it[num].push_front(idx);    // adding to left
        else
            it[num].push_back(idx);     // adding to right
 
        bool aft = is_arth_prg(num);    // if there is an arth.prg of num now
        if(!bef && aft)     // if arth.prg wasn't before but is now (this can only happen if the list was empty)
            cnt_arth++;     // new arth.prg
        else if(bef && !aft) // was before but not anymore
            cnt_arth--;
    }
 
    void rmv(int num, bool pole)
    {
        cnt[num]--;
        if(!cnt[num])   // cnt[num] = 0 means all the nums have been removed
            distinct--;
        bool bef = is_arth_prg(num);    // if arth.prg of num already exists
 
        if(pole)
            it[num].pop_front();    // removing from left
        else
            it[num].pop_back();     // removing from right
 
        bool aft = is_arth_prg(num);    // if there is an arth.prg of num now
        if(!bef && aft)     // if arth.prg wasn't before but is now
            cnt_arth++;     // new arth.prg
        else if(bef && !aft) // was before but not anymore (this can only happen if the list is now empty)
            cnt_arth--;
    }
 
    inline int answer()
    {
        return distinct + (cnt_arth ? 0 : 1);
    }
};
 
int main()
{
    int n, q;
    read(n);
    vi a(n);
    for(int i=0; i<n; i++)
        read(a[i]);
 
    MO mo(a);
    int block = sqrt(n+1);
 
    read(q);
    vector<Query> qr(q);
 
    for(int i=0; i<q; i++)
    {
        read2(qr[i].l, qr[i].r);
        qr[i].l--;      // to make 0 indexed
        qr[i].r--;
        qr[i].id = i;
    }
    sort(all(qr),
        [block](const Query &a, const Query &b) -> bool
        {
            if(a.l/block == b.l/block)
                return (a.r < b.r);
            return (a.l/block < b.l/block);
        });
 
    vi ans(q);
    int mo_left = 0, mo_right = -1;
    for(Query &x: qr)
    {
        while(mo_right < x.r)
        {
            mo.add(a[++mo_right],mo_right,0);
        }
        while(mo_right > x.r)
        {
            mo.rmv(a[mo_right--],0);
        }
        while(mo_left < x.l)
        {
            mo.rmv(a[mo_left++],1);
        }
        while(mo_left > x.l)
        {
            mo.add(a[--mo_left],mo_left,1);
        }
        ans[x.id] = mo.answer();
    }
 
    for(int i=0; i<q; i++)
        printf("%d\n", ans[i]);
 
    return 0;
}