//Really simple implementation, probably only useful as an intro to implementations.
//I think overloading the [] operator to make an array into a circular array would be cooler, but i digress.
#include <iostream>
using namespace std;
char circularAt(char arr[], int n, int ind)
{
    return arr[ind % n];
}
int main()
{
    char arr[] = {'A', 'B', 'C', 'D', 'E'};
    int size = sizeof(arr)/sizeof(char);
    for(int i = 0; i < 50; i ++)
    {
        char c = circularAt(arr, size, i);
        cout << c << " ";
    }
}