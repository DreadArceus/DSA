//This is the brute force, simple math approach
//Further mathematics can supposedly make this O(1)
#include <iostream>
using namespace std;
int main()
{
    int X = 0, Y = 0, s = 0, T = 0, cnt = 0;
    cin >> X >> Y >> s >> T;
    for(int x = X; x <= X + s; x++)
    {
        for(int y = Y; y <= Y + s; y++)
        {
            if(x + y <= T)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}