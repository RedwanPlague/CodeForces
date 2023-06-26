// https://codeforces.com/problemset/problem/630/Q
 
#include <cstdio>
#include <cmath>
 
const double PI = acos(-1);
 
int main()
{
    int l1, l2, l3;
    while(scanf("%d %d %d", &l1, &l2, &l3) != EOF)
    {
        double B1 = 3.0 / 4 * l1 * l1 / tan(PI/3); // base area of the pyramids
        double B2 = 4.0 / 4 * l2 * l2 / tan(PI/4);
        double B3 = 5.0 / 4 * l3 * l3 / tan(PI/5);
 
        double h1 = l1 * sqrt(1 - 1/(4*sin(PI/3)*sin(PI/3))); // height of the pyramids
        double h2 = l2 * sqrt(1 - 1/(4*sin(PI/4)*sin(PI/4)));
        double h3 = l3 * sqrt(1 - 1/(4*sin(PI/5)*sin(PI/5)));
 
        double V1 = B1 * h1 / 3; // volume of the pyramids 
        double V2 = B2 * h2 / 3;
        double V3 = B3 * h3 / 3;
 
        printf("%.12f\n", V1+V2+V3);
    }
    return 0;
}