//A very natural algorithm, used this way before formally knowing it.
//The idea is to iterate over some DS except we do stuff with more than a single item in a single iteration
//For example, go through an array looking at 2 elements at once to calculate the max consecutive pair sum
//The above example is demonstrated below:
#include <iostream>
using namespace std;
int slidingWindow(int a[], int n)
{
    int max = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(max < a[i] + a[i+1])
        {
            max = a[i] + a[i+1];
        }
    }
    return max;
}
int main()
{
    int n = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxSumOfPair = slidingWindow(a, n);
    cout << maxSumOfPair;
}