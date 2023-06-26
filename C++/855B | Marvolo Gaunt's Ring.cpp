#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, p, q, r;
    cin>>n>>p>>q>>r;
    long long ar[n], minL[n], maxL[n], minR[n], maxR[n];
    cin>>ar[0];
    minL[0] = maxL[0] = ar[0];
    for(int i=1; i<n; i++)
    {
        cin>>ar[i];
        maxL[i] = max(maxL[i-1], ar[i]);
        minL[i] = min(minL[i-1], ar[i]);
    }
    minR[n-1] = maxR[n-1] = ar[n-1];
    for(int i=n-2; i>=0; i--)
    {
        maxR[i] = max(maxR[i+1], ar[i]);
        minR[i] = min(minR[i+1], ar[i]);
    }
    long long maxAns = LLONG_MIN, ans;
    for(int i=0; i<n; i++)
    {
        ans = q*ar[i];
        if(p<0)
            ans += p*minL[i];
        else
            ans += p*maxL[i];
        if(r<0)
            ans += r*minR[i];
        else
            ans += r*maxR[i];
        maxAns = max(maxAns,ans);
    }
    cout<<maxAns<<endl;
    return 0;
}