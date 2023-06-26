#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
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
 
    int n;
    cin >> n;
    vi a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    vi mark(32,-1);
    for(int i=0; i<32; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[j]&(1<<i))
            {
                if(mark[i] == -1)
                    mark[i] = j;
                else
                {
                    mark[i] = -1;
                    break;
                }
            }
        }
    }
    int hmm = -1;
    for(int i=31; i>=0; i--)
    {
        if(mark[i] != -1)
        {
            hmm = mark[i];
            cout << a[hmm] << ' ';
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i != hmm)
            cout << a[i] << ' ';
    }
    cout << endl;
 
    return 0;
}