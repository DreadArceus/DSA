#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int a[], int x, int n)
{
    int* start = a;
    int* end = a + n;
    while(start != end)
    {
        int* mid = a + (start - a + end - a)/2;
        if(*mid == x)
        {
            return mid - a;
        }
        else if(*mid > x)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
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
    sort(a, a + n);

    int t = 0;
    cin >> t;
    while(t--)
    {
        int x = 0;
        cin >> x;
        cout << binarySearch(a, x, n) + 1 << "\n";
    }
}