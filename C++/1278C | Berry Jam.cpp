#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 100005
#define MOD 1000000007
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
 
    int b[2*MX];
    int h[2*MX];
    int *id = b+MX;
 
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i=0; i<2*n; i++)
            cin >> h[i];
        memset(b,-1,sizeof(b));
        int sum = 0;
        id[0] = 2*n;
        for(int i=2*n-1; i>=n; i--)
        {
            if(h[i] == 1)
                sum--;
            else
                sum++;
            id[sum] = i;
        }
 
        /*cout << "this: ";
        for(int i=-n; i<=n; i++)
            cout << id[i] << ' ';
        cout << endl;*/
 
        sum = 0;
        int mn = id[0];
        for(int i=0; i<n; i++)
        {
            if(h[i] == 1)
                sum--;
            else
                sum++;
            if(id[-sum] != -1)
                mn = min(mn,id[-sum]-(i+1));
        }
        cout << mn << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 