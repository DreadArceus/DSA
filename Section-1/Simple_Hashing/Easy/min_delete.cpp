#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int *hashTable = new int(INT32_MAX);
    int maxFreq = 0;
    for(int i = 0; i < n; i++)
    {
        if(++hashTable[ar[i]] > maxFreq)
        {
            maxFreq = hashTable[ar[i]];
        }
    }
    cout << n - maxFreq;
}