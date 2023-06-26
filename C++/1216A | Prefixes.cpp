#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i=0; i<n; i+=2)
    {
        if(s[i] == 'a' && s[i+1] == 'a')
        {
            s[i+1] = 'b';
            cnt++;
        }
        else if(s[i] == 'b' && s[i+1] == 'b')
        {
            s[i] = 'a';
            cnt++;
        }
    }
    cout << cnt << '\n' << s << endl;
    return 0;
}