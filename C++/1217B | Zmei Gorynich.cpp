#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, X;
        scanf("%d %d", &n, &X);
 
        int ans = INT_MAX;
        int max_d = -1, max_diff = -1;
 
        for(int i=0; i<n; i++)
        {
            int d, h;
            scanf("%d %d", &d, &h);
            int diff = d - h;
 
            if(d >= X)
                ans = 1;
 
            max_d = max(max_d,d);
            max_diff = max(max_diff, diff);
        }
 
        if(ans > 1 && max_diff > 0)
        {
            ans = 1 + (X-max_d-1)/max_diff + 1;
        }
 
        if(ans == INT_MAX)
            ans = -1;
 
        printf("%d\n", ans);
    }
    return 0;
}