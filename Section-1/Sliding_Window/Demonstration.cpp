//A very natural algorithm, used this way before formally knowing it.
//The idea is to iterate over some DS except we do stuff with more than a single item in a single iteration
//For example, go through an array looking at k elements at once to calculate the max k-consecutive sum
//The above example is demonstrated below: [O(n)]
#include <iostream>
using namespace std;
int slidingWindow(int a[], int n, int k)
{
    assert(k <= n);
    int currSum = 0;
    for(int i = 0; i < k; i++) //making the initial window
    {
        currSum += a[i];
    }
    int maxSum = currSum;
    for(int i = k; i < n; i++) //check for bigger sums and move the window forward
    {
        currSum += a[i] - a[i-k];
        if(maxSum < currSum)
        {
            maxSum = currSum;
        }
    }
    return maxSum;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxSumOfPair = slidingWindow(a, n, k);
    cout << maxSumOfPair;
}