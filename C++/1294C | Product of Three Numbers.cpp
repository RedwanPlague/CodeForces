#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> pii;
 
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, a = -1, b = -1, c;
        cin >> n;
        int lim = sqrt(n+.0);
        for(int i=2; i<=lim; i++) 
        {
            if(n%i == 0)
            {
                a = i;
                break;
            }
        }
        if(a != -1)
        {
            n /= a;
            lim = sqrt(n+.0);
            for(int i=a+1; i<=lim; i++)
            {
                if(n%i == 0)
                {
                    b = i;
                    c = n/b;
                    break;
                }
            }
        }
        
        if(a != -1 && b != -1 && a != b && b != c && c != a)
            cout << "YES\n" << a << ' ' << b << ' ' << n/b << '\n';
        else 
            cout << "NO\n";
    }
    
    return 0;
}