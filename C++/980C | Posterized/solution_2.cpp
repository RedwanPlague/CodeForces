#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main()
{
    int n, k, color;
    scanf("%d %d", &n, &k);
 
    int key[257];
    memset(key, -1, sizeof(key));
 
    for(int i=0; i<n; i++)
    {
        scanf("%d", &color);
        if(key[color] != -1)
        {
            printf("%d ", key[color]);
            continue;
        }
        int found = color-1;
        while(found >= 0)
        {
            if(key[found] != -1)
                break;
            found--;
        }
        if(found == -1 || key[found] + k - 1 < color)
        {
            found = max(found+1, color-k+1);
            for(int j=found; j<=color; j++)
                key[j] = found;
        }
        else
        {
            for(int j=found+1; j<=color; j++)
                key[j] = key[found];
        }
        printf("%d ", key[color]);
    }
 
    return 0;
}