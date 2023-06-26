#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, l, r;
    while(scanf("%d %d %d", &n, &l, &r) != EOF)
    {
        printf("%d %d\n", ((1<<l)-1) + 1*(n-l),  ((1<<r)-1) + (1<<(r-1))*(n-r));
    }
    return 0;
}