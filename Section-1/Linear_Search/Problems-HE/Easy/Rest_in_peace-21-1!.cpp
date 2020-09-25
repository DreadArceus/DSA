//Easy problem, also sprintf exists.
#include <iostream>
#include <string>
using namespace std;
bool solve(int x)
{
    if(x % 21 == 0 && x >= 21)
    {
        return true;
    }
    string s = to_string(x);
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == '2' && s[i + 1] == '1')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int x = 0;
        cin >> x;
        cout << ((solve(x)) ? "The streak is broken!" : "The streak lives still in our heart!") << "\n";
    }
}