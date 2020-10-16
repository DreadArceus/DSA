//running total/cumulative sum/prefix sum is trivial to implement as shown below
//however it can be very useful, see applications
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int prefix_sum_array[n];
    prefix_sum_array[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefix_sum_array[i] = prefix_sum_array[i-1] + a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << prefix_sum_array[i] << " ";
    }
}