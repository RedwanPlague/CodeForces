#include <stdio.h>
 
typedef long long ll;
 
const int MX = 500005;
 
int main() 
{
 int N;
 ll a[MX], cnt[MX];
 scanf("%d", &N);
 
 ll sum = 0;
 for(int i=0; i<N; i++)
 {
     scanf("%I64d", &a[i]);
     sum += a[i];
 }
 
 if(sum%3 != 0)
 {
     puts("0");
     return 0;
 }
 
 sum /= 3;
 ll cur_sum = 0;
 cnt[N] = cnt[N+1] = 0;
 for(int i=N-1; i>=0; i--)
 {
     cur_sum += a[i];
     cnt[i] = cnt[i+1];
     if(cur_sum == sum)
         cnt[i]++;
 }
 
 ll ans = 0;
    cur_sum = 0;
    for(int i=0; i<N; i++)
    {
        cur_sum += a[i];
        if(cur_sum == sum)
            ans += cnt[i+2];
    }
    
    printf("%I64d\n", ans);
 
 return 0;
}