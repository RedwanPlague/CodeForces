#include <stdio.h>
#include <algorithm>
 
int istri(int a, int b, int c)
{
    if((a+b)>c && (b+c)>a && (c+a)>b) return 1;
    return 0;
}
 
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    std::sort(a,a+n);
    for(i=2; i<n; i++) {
        if(istri(a[i],a[i-1],a[i-2])) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}