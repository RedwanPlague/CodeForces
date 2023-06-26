#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
 
int main()
{
    int n;
    scanf("%d", &n);
    int a[305];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int limit = n/2;
    for(int i=n-2; i>0; i--)
    {
        if(i < limit)
        {
            a[i] -= a[i-1];
        }
        else
        {
            a[i] -= a[n-2-i];
        }
    }
    /*for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    puts("");*/
    vector <int> v;
    vector < pair<int,int> > ans;
    int ver = 1;
    if(n&1)
    {
        for(int k=0; k<=a[limit]; k++)
            v.pb(ver++);
        //puts("first");
        for(int k=0; k<v.size(); k++)
        {
            for(int cnt=0; cnt<k; cnt++)
                ans.pb(make_pair(v[cnt], v[k]));
        }
    }
    else
    {
        v.pb(1);
        ver = 2;
    }
    int dk_1 = (n%2 == 0) ? 0 : a[limit];
    int i = limit - 1;
    int j = (n%2 == 0) ? limit : limit + 1;
    int dk, d1 = 0;
    while(i >= 0 && j < n)
    {
        d1 = a[i];
        dk = a[j];
        dk -= dk_1;
        for(int k=0; k<dk; k++)
            v.pb(ver++);
        //printf("%d %d %d\n", d1, dk_1, dk);
        for(int k=v.size()-d1; k<v.size(); k++)
        {
            for(int cnt=0; cnt<k; cnt++)
                ans.pb(make_pair(v[cnt], v[k]));
        }
        i--;
        j++;
        dk_1 = a[j-1];
    }
    printf("%d\n", ans.size());
    for(int k=0; k<ans.size(); k++)
        printf("%d %d\n", ans[k].first, ans[k].second);
    return 0;
}