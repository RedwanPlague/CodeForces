#include <stdio.h>
 
int main()
{
    unsigned long long n;
    int i, j;
    scanf("%I64d", &n);
    for(j=1; n>(5*j); j*=2) {
        n-=(5*j);
    }
    n = (n%j==0) ? n/j : n/j+1;
    switch(n) {
    case 1:
        printf("Sheldon");
        break;
    case 2:
        printf("Leonard");
        break;
    case 3:
        printf("Penny");
        break;
    case 4:
        printf("Rajesh");
        break;
    case 5:
        printf("Howard");
        break;
    }
    return 0;
}