#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n;
    cin >> n;
    int g = n/2+1;
    cout << g << '\n';
    int r = 1, c = 1;
    for(int i=0; i<n; i++)
    {
        cout << r << ' ' << c << '\n';
        if(i&1)
            r++;
        else 
            c++;
    }
    return 0;
}