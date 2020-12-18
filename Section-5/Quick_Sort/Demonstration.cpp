//v2
//Implementing the widely used quick sort logic
//Used nested while loop, so test case #3 on HE still timed out
//However the idea is accurate
#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> quickSort(vector<int> v, int start, int end)
{
    if(start >= end)
    {
        return v;
    }

    int pivot = rand() % (end - start + 1) + start;
    int pivot_value = v[pivot];
    v[pivot] = v[end];
    v[end] = pivot_value;
    pivot = end;
    int l = start, r = end - 1;
    while(true)
    {
        while(l < end && v[l] < pivot_value)
        {
            l++;
        }
        while(r >= start && v[r] >= pivot_value)
        {
            r--;
        }
        pivot = r + 1;
        if(l >= r)
        {
            break;
        }
        int temp = v[l];
        v[l] = v[r];
        v[r] = temp;
        pivot = r;
    }
    v[end] = v[pivot];
    v[pivot] = pivot_value;

    v = quickSort(v, start, pivot - 1);
    v = quickSort(v, pivot + 1, end);

    return v;
}

int main()
{
    freopen("/Users/dreadarceus/github/DSA/Section-5/Quick_Sort/inp.txt", "r", stdin);
    freopen("/Users/dreadarceus/github/DSA/Section-5/Quick_Sort/output.txt", "w", stdout);
    srand(time(0));
    int n = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    v = quickSort(v, 0, n - 1);
    for(int x : v)
    {
        cout << x << " ";
    }
}