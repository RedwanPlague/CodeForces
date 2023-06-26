#include <stdio.h>
int gcd(int a, int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int n, m, z;
    scanf("%d %d %d", &n, &m, &z);
    printf("%d", z/lcm(n,m));
    return 0;
}