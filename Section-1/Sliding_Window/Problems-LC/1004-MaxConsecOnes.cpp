//v1: Brute Force
//v2: Sliding Window
//v3: Teleporting Window
//v4: Memory Abuse O(N)
//      All cases passed - Runtime: 71.81 %ile, Memory Usage: 7.71 %ile
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> A, int K)
{
    int maxCnt = 0, cnt = 0, locK = K, passedZ = 0, leftZ = 0;
    vector<int> zeroTracker(A.size(), 0);
    zeroTracker[0] = -1;
    for(int i = 0; i < A.size(); i++)
    {
        if(K == 0 && A[i] == 0)
        {
            cnt = 0;
            continue;
        }
        if(A[i] == 0)
        {
            zeroTracker[passedZ] = i + 1;
            passedZ++;
            if(locK == 0)
            {
                locK = 1;
                cnt -= zeroTracker[leftZ] - ((leftZ == 0) ? 0 : zeroTracker[leftZ-1]);
                leftZ++;
            }
            locK--;
        }
        cnt++;
        if(cnt > maxCnt)
        {
            maxCnt = cnt;
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