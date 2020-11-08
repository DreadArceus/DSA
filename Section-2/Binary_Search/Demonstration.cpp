//the right shifts are inaccurate with my prototype (so left->right~ results in a SEGFAULT)
//correcting that and converting recursion into a loop
//v2: 2-Pointer
#include <iostream>
using namespace std;

int binarySearch(int a[], int x, int n)
{
    int* start = a;
    int* end = a + n;
    while(end - start != 0)
    {
        int *y = a + (start - a + end - a)/2;
        if(*y < x)
        {
            start = y + 1;
        }
        else if(*y > x)
        {
            end = y;
        }
        else
        {
            return y - a;
        }
    }
    return -1;
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
        int ansIndex = binarySearch(ar, x, n);
        cout << ansIndex << "\n";
    }
}