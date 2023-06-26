#include <cstdio>
#include <cstring>
 
#define MOD 1000000007
 
void add(int &a, const int &b)
{
    a += b;
    if(a >= MOD)
        a -= MOD;
}
 
int main()
{
    int dp[2][200005];
    // it should be dp[maxH][maxR], dp[h][i] = ways to make towers of height 'h' using 'i' red blocks
    // but since h is only affected by h-1 we save only the previous state in one of these (dp[2]..) two arrays and use the other for current state
    // instead of one two-dimensional array
    int r, g;
    scanf("%d %d", &r, &g);
    int total = 0, use = 1; // use = gives which array to use; (1 - use) has the previous state saved; we could also use (h&1) if we wanted
    int ans = 0;
    dp[0][0] = 1; // base case; 1 way to make tower of height 0 using 0 red blocks... use nothing :)
    for(int h = 1; h < 900; h++)
    {
        total += h;
        memset(dp[use], 0, sizeof(dp[use])); // dp[h&1] would work fine :)
        int curAns = 0;
        for(int i = 0; i <= r; i++)
        {
            if(i >= h)
                add(dp[use][i], dp[1-use][i-h]); // taking red blocks
            if(total - i <= g) // if there are enough green balls to use; in this step there are 'total' balls used... of them i'm saying 'i' are red... so the rest need to be green.
                add(dp[use][i], dp[1-use][i]);
            add(curAns, dp[use][i]);
        }
        if(curAns)
            ans = curAns;
        use = 1 - use; // only problem with using 'use' instead of (h&1) is... forgetting to write this line :3
    }
    printf("%d\n", ans);
    return 0;
}