#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, color;
    cin>>n>>k;
 
    int key[257];
    memset(key, -1, sizeof(key));
 
    for(int i=0; i<n; i++)
    {
        cin>>color;
        if(key[color] != -1)
        {
            cout<<key[color]<<' ';
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
        cout<<key[color]<<' ';
    }
 
    return 0;
}