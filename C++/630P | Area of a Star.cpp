// https://codeforces.com/problemset/problem/630/P
 
#include <cstdio>
#include <cmath>
 
const double PI = acos(-1);
 
int main()
{
    int n, r;
    while(scanf("%d %d", &n, &r) != EOF)
    {
        double area = double(n) * r * r / (1/tan(PI/n) + 1/tan(PI/2/n));
        printf("%.12f\n", area);
    }
    return 0;
}