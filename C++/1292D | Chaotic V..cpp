#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 5001
#define MP 700 // 669 primes in range [1,5000]
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
vi prime;
vector<bool> isp(MX,true);
void sieve()
{
    int limit = sqrt(MX+.0);
    isp[0] = isp[1] = false;
    prime.push_back(2);
    for(int i=4; i<MX; i+=2)
        isp[i] = false;
    for(int i=3; i<MX; i+=2)
    {
        if(isp[i])
        {
            prime.push_back(i);
            if(i < limit)
            {
                for(int j=i*i; j<MX; j+=2*i)
                    isp[j] = false;
            }
        }
    }
}
 
ll dp[MX][MP]; 
 
void build_dp()
{
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<MX; i++)
    {
        int temp = i;
        for(int j=0; j<prime.size(); j++)
        {
            dp[i][j] = dp[i-1][j];
            while(temp % prime[j] == 0)
            {
                temp /= prime[j];
                dp[i][j]++;
            }
        }
    }
}
 
void cumulate_dp() // cumulates the rows of dp
{
    for(int i=2; i<MX; i++)
        for(int j=1; j<MP; j++)
            dp[i][j] += dp[i][j-1];
}
 
void print_dp()
{
    for(int i=0; i<10; i++)
    {
        cout << i << " --> ";
        for(int j=0; j<4; j++)
        {
            cout << prime[j] << "->" << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
int lpf(int n, int k) // returns k-th largest prime factor of n! (but instead of returning 2 it returns 0, since 2 is the 0th prime)
{
    return lower_bound(dp[n], dp[n]+MP, dp[n][MP-1]-k) - dp[n] ;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    sieve();
    build_dp();
    //print_dp();
    cumulate_dp();
    //print_dp();
    
    int n, temp;
    cin >> n;
    vi mark(MX,0);
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        if(temp > 1)
        {
            mark[temp]++;
            sum += dp[temp][MP-1];
        }
    }
 
    for(int it=0; ; it++) // atmost 60000 times
    {
        vi track(MP,0);
        int mx = 0, mxidx = -1;
        for(int k=0; k<MX; k++)
        {
            if(!mark[k] || dp[k][MP-1] <= it)
                continue;
            int idx = lpf(k,it);
            track[idx] += mark[k];
            if(track[idx] > mx)
            {
                mx = track[idx];
                mxidx = idx;
            }
        }
        if(mx <= n-mx)
            break;
        for(int k=0; k<MX; k++)
        {
            if(!mark[k] || dp[k][MP-1] <= it)
                continue;
            int idx = lpf(k,it);
            if(idx != mxidx)
                mark[k] = 0;
        }
        sum += n-mx;
        sum -= mx;
    }
 
    cout << sum << endl;
 
    return 0;
}