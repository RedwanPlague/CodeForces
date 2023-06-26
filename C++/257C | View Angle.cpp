#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
 
using namespace std;
 
#define read(n) scanf("%d", &n);
#define read2(a,b) scanf("%d %d", &a, &b);
#define all(v) (v).begin(),(v).end()
 
const double PI = acos(-1);
 
double find_angle(int x, int y)
{
    if(x == 0)
    {
        if(y > 0)
            return 90.0;
        return 270.0;
    }
 
    double ret = (180*atan(fabs(y)/fabs(x)))/PI;
 
    if(x > 0)
    {
        if(y >= 0)
            return ret;
        return (360-ret);
    }
 
    if(y >= 0)
        return (180-ret);
    return (180+ret);
}
 
int main()
{
    int n;
    read(n);
    int x, y;
 
    vector<double> angle;
    for(int i=0; i<n; i++)
    {
        read2(x,y);
        angle.push_back(find_angle(x,y));
        //printf("%.10f\n", angle.back());
    }
 
    sort(all(angle));
 
    double ans = angle.back() - angle[0];
    for(int i=1; i<n; i++)
    {
        ans = min(ans, 360 + angle[i-1] - angle[i]);
    }
 
    printf("%.10f\n", ans);
 
    return 0;
}