//My implementation of Binary Search on an Array
#include <iostream>
using namespace std;

int binarySearch(int a[], int mid, int x, int n)
{
    if(a[mid] == x)
    {
        return mid;
    }
    if(a[mid] > x)
    {
        return binarySearch(a, mid/2, x, n);
    }
    return binarySearch(a, (n + mid)/2, x, n);
}

int main()
{
    int n = 0;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int x = 0;
    while(cin >> x)
    {
        int ansIndex = binarySearch(ar, n/2, x, n);
        cout << ansIndex << "\n";
    }
}