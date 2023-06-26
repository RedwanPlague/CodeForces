#include <bits/stdc++.h>
using namespace std;
struct dragon {
    int st;
    int pn;
} a[1000];
 
bool cmp(struct dragon a, struct dragon b)
{
    return a.st<b.st;
}
 
int main()
{
    int n, s, i;
    scanf("%d %d", &s, &n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &a[i].st, &a[i].pn);
    }
    sort(a,a+n,cmp);
    for(i=0; i<n; i++) {
        if(s<=a[i].st) {
            puts("NO");
            return 0;
        }
        s+=a[i].pn;
    }
    puts("YES");
    return 0;
}