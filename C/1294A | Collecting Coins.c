#include <stdio.h>
 
int main()
{
    int t, a, b, c, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &n);
        int tot = a+b+c+n;
        if(tot%3)
        {
            puts("NO");
        }
        else 
        {
            int each = tot/3;
            if(a <= each && b <= each && c <= each)
                puts("YES");
            else 
                puts("NO");
        }
    }
    
    return 0;
}