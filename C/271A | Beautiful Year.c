#include <stdio.h>
int main()
{
    int i, y, a[10], Y;
    scanf("%d", &y);
    for(y++; y<=9500; y++)
    {
        for(i=0; i<10; i++)
            a[i]=0;
        Y=y;
        while(Y!=0) {
            a[Y%10]++;
            Y/=10;
        }
        for(i=0; i<10; i++)
            if(a[i]>1)
                break;
        if(i==10)
            break;
    }
    printf("%d", y);
    return 0;
}