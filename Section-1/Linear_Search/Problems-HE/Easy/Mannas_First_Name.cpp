//The solution i did is the most low level C style solution, basically.
//However this can be generalised/done in fewer lines of code with some algorithms
//Coming back to this question later someday -9-September-2020
#include <iostream>
#include <string>
using namespace std;
int cntSUVO(string s)
{
    int cnt = 0;
    for(int i = 0; i < s.length() - 3; i++)
    {
        if(s[i] == 'S' && s[i+1] == 'U' && s[i+2] == 'V' && s[i+3] == 'O')
        {
            cnt++;
        }
    }
    return cnt;
}
int cntSJIT(string s)
{
    int cnt = 0;
    for(int i = 0; i < s.length() - 6; i++)
    {
        if(s[i] == 'S' && s[i+1] == 'U' && s[i+2] == 'V' && s[i+3] == 'O' 
            && s[i+4] == 'J' && s[i+5] == 'I' && s[i+6] == 'T')
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        string S = "";
        cin >> S;
        cout << "SUVO = " << cntSUVO(S) - cntSJIT(S) << ", SUVOJIT = " << cntSJIT(S) << "\n";
    }
}