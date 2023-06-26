#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define read(n) scanf("%d", &n)
 
int n;
int dp[1001][1001];
int which[1001][1001];
int time[1001];
 
int quick(int i, int j)
{
    if(j >= n)
    {
        if(i >= n)
            return 0;
        return time[i];
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret = max(time[i], time[j]) + quick(j+1, j+2);
    if(j+1 < n)
    {
        int ret1 = max(time[i], time[j+1]) + quick(j, j+2);
        int ret2 = max(time[j], time[j+1]) + quick(i, j+2);
        if(ret1 < ret)
        {
            which[i][j] = 1;
            ret = ret1;
        }
        if(ret2 < ret)
        {
            which[i][j] = 2;
            ret = ret2;
        }
    }
    return (dp[i][j] = ret);
}
 
int main()
{
    read(n);
    for(int i=0; i<n; i++)
        read(time[i]);
    memset(dp, -1, sizeof(dp));
    memset(which, 0, sizeof(which));
    printf("%d\n", quick(0,1));
 
    /*puts("");
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", which[i][j]);
        }
        puts("");
    }
 
    puts("");
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", which[i][j]);
        }
        puts("");
    }*/
 
    int i = 0, j = 1;
 
    while(1)
    {
        if(j >= n)
        {
            if(i < n)
                printf("%d\n", i+1);
            break;
        }
        if(which[i][j] == 0)
        {
            printf("%d %d\n", i+1, j+1);
            i = j+1;
            j = j+2;
        }
        else if(which[i][j] == 1)
        {
            printf("%d %d\n", i+1, j+2);
            i = j;
            j = j+2;
        }
        else
        {
            printf("%d %d\n", j+1, j+2);
            j = j+2;
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 