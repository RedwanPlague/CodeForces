#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n, m;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
        cin>>b[i];
    sort(b,b+m);
    int pair = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i])
        {
            for(int j=0; j<m; j++)
            {
                if(b[j] && abs(a[i]-b[j])<=1)
                {
                    a[i] = 0;
                    b[j] = 0;
                    pair++;
                    break;
                }
            }
        }
    }
    cout<<pair<<endl;
    return 0;
}