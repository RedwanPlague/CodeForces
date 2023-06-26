#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
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
 
    int T;
    cin >> T;
    while(T--)
    {
        string hash, s;
        cin >> s >> hash;
        vi cnts(26,0);
        for(auto c: s)
            cnts[c-'a']++;
        vector<vi> prec(hash.size()+1,vi(26,0));
        for(int i=0; i<hash.size(); i++)
        {
            for(int j=0; j<26; j++)
                prec[i+1][j] = prec[i][j];
            prec[i+1][hash[i]-'a']++;
        }
 
        /*for(int i=0; i<26; i++)
            cout << cnts[i] << ' ';
        cout << endl;
        for(int i=0; i<=hash.size(); i++)
        {
            for(int j=0; j<26; j++)
                cout << prec[i][j] << ' ';
            cout << endl;
        }*/
 
        bool found = false;
        for(int i=0; i+s.size()-1<hash.size(); i++)
        {
            bool ok = true;
            for(int j=0; j<26; j++)
            {
                if(cnts[j] != (prec[i+s.size()][j] - prec[i][j]))
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                found = true;
                break;
            }
        }
 
        if(found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}