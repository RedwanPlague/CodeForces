#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char time[200];
 
    while(scanf("%s", time) != EOF)
    {
        int len = strlen(time);
        int i;
        for(i=0; i<len; i++)
        {
            if(time[i] == '1')
                break;
        }
 
        int pos = (len-1) - i;
 
        if(pos == -1)
        {
            printf("0\n");
        }
 
        else if(pos&1)
        {
            printf("%d\n", (pos+1)/2);
        }
 
        else
        {
            int ans = pos/2;
            bool larger = false;
 
            for(i++; i<len; i++)
            {
                if(time[i] == '1')
                {
                    larger = true;
                    break;
                }
            }
 
            if(larger)
                ans++;
 
            printf("%d\n", ans);
        }
    }
 
    return 0;
}