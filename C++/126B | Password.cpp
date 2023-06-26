#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
void make_failure_table(const string &pattern, vi &failure)
{
    failure[0] = failure[1] = 0;
    for(int i=2; i<=pattern.length(); i++)
    {
        int last = failure[i-1];
        while(true)
        {
            if(pattern[last] == pattern[i-1])
            {
                failure[i] = last+1;
                break;
            }
            if(last == 0)
            {
                failure[i] = 0;
                break;
            }
            last = failure[last];
        }
    }
}
 
bool KMP(const string &text, const string &pattern, const vi &failure)
{
    int tl = text.length(), pl = pattern.length();
    int i = 1, j = 0;
    while(i < tl-1)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
            if(j == pl)
            {
                return true;
            }
        }
        else if(j == 0)
        {
            i++;
        }
        else
        {
            j = failure[j];
        }
    }
    return false;
}
 
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    vi failure(len+1);
    make_failure_table(s,failure);
    int till = failure[len];
    if(!till)
    {
        cout << "Just a legend" << endl;
        return 0;
    }
    string sub = "";
    for(int i=0; i<till; i++)
        sub += s[i];
    vi fail(till+1);
    make_failure_table(sub,fail);
    if(KMP(s,sub,fail))
    {
        cout << sub << endl;
        return 0;
    }
    till = failure[till];
    if(!till)
    {
        cout << "Just a legend" << endl;
        return 0;
    }
    sub = "";
    for(int i=0; i<till; i++)
        sub += s[i];
    cout << sub << endl;
    return 0;
}