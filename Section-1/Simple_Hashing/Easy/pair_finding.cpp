#include <iostream>
using namespace std;
bool pairCheck(int arr[], int n, int x) 
{
    int *hashTable = new int[100000];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x/2 && hashTable[arr[i]] == 1)
        {
            return true;
        }
        hashTable[arr[i]] = 1;
    }
    for(int i = 1; i < (x+1)/2; i++)
    {
        if(hashTable[i] == 1 && hashTable[x - i] == 1)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n = 0, x = 0;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cin >> x;
    cout << ((pairCheck(ar, n, x) ? "Yes" : "No"));
}