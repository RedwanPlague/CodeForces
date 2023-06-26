#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int T;
    char s[200005];
    int bef[200005], last;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        int cnt = 0;
 
        last = -1;
        for(int i=0; i<n; i++)
        {
            bef[i] = last;
            if(s[i] == '1')
                last = i;
        }
 
        for(int r=n-1; r>=0; r--)
        {
            int val = 0;
            for(int l = r, pos = 0; pos <= 18 && l >= 0; l--, pos++)
            {
                if(s[l] == '1')
                {
                    val += (1 << pos);
                    if((r-l+1)+(l-bef[l]-1) >= val)
                        cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}