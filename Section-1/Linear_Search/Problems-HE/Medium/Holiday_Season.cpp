#include <iostream>
#include <string>
using namespace std;
int solve(string x)
{
    int cnt = 0;
    for(int i = 0; i < x.length(); i++)
    {
        for(int j = i + 2; j < x.length(); j++)
        {
            if(x[i] == x[j])
            {
                for(int a = i + 1; a < j; a++)
                {
                    for(int b = j + 1; b < x.length(); b++)
                    {
                        if(x[a] == x[b])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
int main()
{
    int n = 0;
    string x = "";
    cin >> n >> x;
    int ans = solve(x);
    cout << ans;
}