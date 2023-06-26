#include <iostream>
#include <string>
 
using namespace std;
 
#define MX 5001
#define MOD 1000000007
 
typedef unsigned int ui;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    string s;
    cin >> n >> s;
 
    int match[MX][MX]; // match[i][j] = how far [i,n) and [j,n) match. (i <= j)
 
    for(int i=0; i<n; i++) // matching [i,n) with [n-1,n) will match only 1 digit if s[i] == s[n-1], otherwise 0
    {
        if(s[i] == s[n-1])
            match[i][n-1] = 1;
        else
            match[i][n-1] = 0;
    }
    for(int i=n-2; i>=0; i--) // loop reversed because we need i+1 for i
    {
        for(int j=n-2; j>=i; j--) // need j+1 for j
        {
            if(s[i] == s[j])
                match[i][j] = 1 + match[i+1][j+1]; // 1 + match from next digits
            else
                match[i][j] = 0; // can't match any more if the first digits don't match
        }
    }
 
    ui dp; // dp[i][j] = how many years can [0,j] be divided into if the last year is always [i,j]
    // keeping only one dp variable because dp[i][j] is not needed later, using pre[i][j] is enough
    ui pre[MX][MX]; // pre[i][j] = holds SUM( dp[0][j] to dp[i-1][j] )
 
    pre[0][0] = 0;
    for(int j=0; j<n; j++)
    {
        pre[0][j] = 0;
        pre[1][j] = 1;
    }
    int len, x;
    for(int i=1; i<n; i++)
    {
        if(s[i] == '0')
        {
            for(int j=i; j<n; j++)
            {
                pre[i+1][j] = pre[i][j];
            }
        }
        else
        {
            for(int j=i; j<n; j++)
            {
                len = j - i; // actually 1 less than length
                dp = (pre[i][i-1] - pre[i<len ? 0 : i-len][i-1] + MOD) % MOD;
                if(i-len-1 >= 0)
                {
                    x = match[i-len-1][i];
                    if(x < len+1 && s[i-len-1+x] < s[i+x])
                        dp = (dp + pre[i-len][i-1] - pre[i-len-1][i-1] + MOD) % MOD;
                }
                pre[i+1][j] = (pre[i][j] + dp) % MOD;
            }
        }
 
    }
 
    cout << pre[n][n-1] << endl;
 
    return 0;
}