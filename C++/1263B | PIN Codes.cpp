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
 
void print(int a)
{
    for(int i=1000; i>=1; i/=10)
    {
        cout << a/i;
        a = a - i*(a/i);
    }
    cout << '\n';
}
 
bool match(int v, int id, int a[15], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i != id && v == a[i])
            return true;
    }
    return false;
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
        int n;
        cin >> n;
        int a[15];
        for(int i=0; i<n; i++)
            cin >> a[i];
        int cnt = 0;
        int needed;
 
        for(int i=1; i<n; i++)
        {
            needed = 0;
            while(match(a[i],i,a,n))
            {
                a[i] = a[i] - a[i]%10 + (a[i]+1)%10;
                needed = 1;
            }
            cnt += needed;
        }
 
        cout << cnt << '\n';
        for(int i=0; i<n; i++)
            print(a[i]);
    }
 
    return 0;
}