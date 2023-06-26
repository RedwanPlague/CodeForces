// https://codeforces.com/problemset/problem/630/M
 
#include <cstdio>
 
#define deviation(deg) (deg <= 180 ? deg : 360 - deg)
 
int main()
{
    long long deg;
    while(scanf("%lld", &deg) != EOF)
    {
        deg %= 360;
        deg = (360 - deg) % 360;
        long long min_deg = deviation(deg), dev;
        int min_turn = 0;
        for(int i=1; i<=3; i++)
        {
            deg = (deg + 90) % 360;
            dev = deviation(deg);
            if(dev < min_deg)
            {
                min_deg = dev;
                min_turn = i;
            }
        }
        printf("%d\n", min_turn);
    }
    return 0;
}