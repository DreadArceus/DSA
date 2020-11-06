//v1: simple Sliding Window
//v1.5: first time using illegal moves lol - 16 ms
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int maxVowels(string s, int k)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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