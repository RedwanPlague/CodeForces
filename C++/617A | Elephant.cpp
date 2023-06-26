#include <stdio.h>
int main()
{
    int x, steps;
    scanf("%d", &x);
    steps = x / 5;
    if(x%5)
        steps++;
    printf("%d\n", steps);
    return 0;
}