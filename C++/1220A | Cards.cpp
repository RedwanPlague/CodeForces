#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
 
typedef vector<int> vi;
typedef long long ll;
 
int main()
{
    int n;
    scanf("%d", &n);
    char s[100005];
    scanf("%s", s);
    int one = 0, zero = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'z')
            zero++;
        else if(s[i] == 'n')
            one++;
    }
 
    for(int i=0; i<one; i++)
        printf("1 ");
    for(int i=0; i<zero; i++)
        printf("0 ");
 
    return 0;
}