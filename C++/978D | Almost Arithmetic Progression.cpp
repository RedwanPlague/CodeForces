#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define INF 1000000000
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    int *a = new int[n];
    int *temp = new int[n];
    
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int da[] = {1, 0, -1};
    
    int minC = INF;
    
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            temp[0] = a[0] + da[x];
            temp[1] = a[1] + da[y];
            int d = temp[1] - temp[0];
            int cnt = abs(da[x]) + abs(da[y]);
            bool valid = true;
            for(int i=2; i<n; i++)
            {
                temp[i] = a[i];
                if(temp[i]-temp[i-1] == d)
                    continue;
                else if(temp[i]+1-temp[i-1] == d)
                {
                    temp[i]++;
                    cnt++;
                }
                else if(temp[i]-1-temp[i-1] == d)
                {
                    temp[i]--;
                    cnt++;
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            if(valid && cnt < minC)
                minC = cnt;
        }
    }
    
    if(minC == INF)
        minC = -1;
        
    cout<<minC<<endl;
    
    delete[] temp;
    delete[] a;
    
    return 0;
}