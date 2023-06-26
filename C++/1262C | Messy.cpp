#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
#define MOD 998244353
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    while(T--)
    {
        int n, k;
        char ch;
        cin >> n >> k;
        string s;
        cin >> s;
        
        cout << n << '\n';
        for(int i=0; i<n-1; i++)
        {
            if(i&1) 
            {
                ch = ')';   
            }
            else
            {
                ch = '(';
            }
            int j;
            for(j=i; j<n; j++)
                if(s[j] == ch)
                    break;
            cout << i+1 << ' ' << j+1 << '\n';
            reverse(s.begin()+i, s.begin()+j+1);
            //cout << s << '\n';
        }
 
        cout << "2 " << max(2,n-2*k+1) << '\n';
        reverse(s.begin()+1, s.begin()+max(1,n-2*k)+1);
        //cout << s << '\n';
 
    }
 
    return 0;
}