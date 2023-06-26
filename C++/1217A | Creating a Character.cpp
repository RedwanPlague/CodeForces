#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int x, y, n;
        scanf("%d %d %d", &x, &y, &n);
        int diff = x-y;
        int ans;
        if(diff > n)
            ans = n+1;
        else if(diff <= -n)
            ans = 0;
        else
        {
            if((n+diff)%2 == 0)
                diff--;
            ans = (diff+n)/2+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}