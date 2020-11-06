//v1: simple Sliding Window
// 28 ms runtime beats 70%+
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int maxVowels(string s, int k)
{
    int maxV = 0, currentV = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(isVowel(s[i]))
        {
            currentV++;
        }
        if(i > k - 1 && isVowel(s[i - k]))
        {
            currentV--;
        }
        if(maxV < currentV)
        {
            maxV = currentV;
        }
    }
    return maxV;
}

int main()
{
    int k = 0;
    string s = "";
    cin >> s >> k;
    int ans = maxVowels(s, k);
    cout << ans;
}