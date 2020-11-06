//v1: Brute Force
//v2: Sliding Window
//v3: Teleporting Window
//v4: Memory Abuse O(N)
//v5: Sliding Window + v4 == All cases passed without memory abuse (55.9 mb/O(1) space, O(N) time)
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> A, int K)
{
    int maxCnt = 0, l = 0, ogK = K;
    for(int r = 0; r < A.size(); r++)
    {
        if(A[r] == 0)
        {
            if(ogK == 0)
            {
                l = r + 1;
                continue;
            }

            if(K == 0)
            {
                for(int i = l; i < r; i++)
                {
                    if(A[i] == 0)
                    {
                        l = i + 1;
                        break;
                    }
                }
            }
            else
            {
                K--;
            }
        }
        if(r - l + 1 > maxCnt)
        {
            maxCnt = r - l + 1;
        }
    }
    return maxCnt;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = solve(v, k);
    cout << ans;
}