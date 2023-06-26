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
 
    string a,b;
    for(int i=0; i<300; i++)
        a += 'a';
    for(int i=0; i<300; i++)
        b += 'b';
 
    int A, B, n, in;
    cout << a << endl;
    cin >> in;
    A = 300-in;
    cout << b << endl;
    cin >> in;
    B = 300-in;
    n = A + B;
    string ans;
    for(int i=0; i<n; i++)
        ans += 'a';
 
    for(int i=0; i<n-1; i++)
    {
        ans[i] = 'b';
        cout << ans << endl;
        cin >> in;
        if(in == B-1)
        {
            B--;
        }
        else
        {
            ans[i] = 'a';
            A--;
        }
    }
 
    if(A)
        ans[n-1] = 'a';
    else
        ans[n-1] = 'b';
 
    cout << ans << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 