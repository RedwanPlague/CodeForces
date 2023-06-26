#include <iostream>
#include <vector>
#include <algorithm>
 
#define F first
#define S second
 
using namespace std;
 
typedef vector<int> vi;
 
class BIT
{
    vi ar;
 
public:
 
    BIT(int n)
    {
        ar.assign(n+1,0);
    }
 
    int query(int idx)
    {
        int mx = 0;
        while(idx > 0){
             mx = max(mx, ar[idx]);
             idx -= idx&(-idx);
        }
        return mx;
    }
 
    void update(int idx, int x) //n is the size of the array, x is the number to add
    {
        while(idx < ar.size())
        {
            ar[idx] = max(ar[idx], x);
            idx += idx&(-idx);
        }
    }
 
};
 
int lis(vi v)
{
    int n = v.size();
    vector< pair<int,int> > comp(n); // used to compress the numbers in v
    for(int i=0; i<n; i++)
    {
        comp[i].F = v[i];
        comp[i].S = i;
    }
    sort(comp.begin(), comp.end());
    for(int i=0; i<comp.size(); i++)
    {
        v[comp[i].S] = i+1;
    }
 
    BIT tree(n);
 
    tree.update(v[0],1);
    for(int i=1; i<n; i++)
    {
        tree.update(v[i],tree.query(v[i]-1)+1);
    }
 
    return tree.query(n);
}
 
int main()
{
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 int n;
 cin >> n;
 
 vi a(n);
 
 for(int i=0; i<n; i++)
        cin >> a[i];
 
    cout << lis(a) << endl;
 
 return 0;
}