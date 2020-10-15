#include <iostream>
using namespace std;
bool checkSubarray(int a1[], int a2[], int n1, int n2)
{
    int* hashTable = new int[INT32_MAX];
    for(int i = 0; i < n1; i++)
    {
        hashTable[a1[i]] = 1;
    }
    for(int i = 0; i < n2; i++)
    {
        if(hashTable[a2[i]] != 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
       int n1 = 0, n2 = 0;
       cin >> n1 >> n2;
       int a1[n1], a2[n2];
       for(int i = 0; i < n1; i++)
       {
           cin >> a1[i];
       }
       for(int i = 0; i < n2; i++)
       {
           cin >> a2[i];
       }
       cout << (checkSubarray(a1, a2, n1, n2) ? "Yes\n" : "No\n");
    }
}