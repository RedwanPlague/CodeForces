#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(2*n); 
        for(int i=0; i<2*n; i++)
            scanf("%d", &a[i]);
        sort(a.begin(),a.end());
        printf("%d\n", a[n]-a[n-1]);
    }
 
    return 0;
}