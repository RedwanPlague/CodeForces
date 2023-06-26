#include <stdio.h>
 
int main()
{
    int n;
    scanf("%d", &n);
    int a, odd, even, no=0, ne=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        if(a%2) no++, odd=i+1;
        else ne++, even=i+1;
    }
    if(no==1) printf("%d", odd);
    else printf("%d", even);
    return 0;
}