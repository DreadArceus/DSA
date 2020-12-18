//v2.5
//TLE was fixed by changing vectors for normal arrays
#include <iostream>
#include <vector>
#include <random>
using namespace std;

void quickSort(int v[], int start, int end)
{
    if(start >= end)
    {
        return;
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

    quickSort(v, start, pivot - 1);
    quickSort(v, pivot + 1, end);
}

int main()
{
    freopen("/Users/dreadarceus/github/DSA/Section-5/Quick_Sort/inp.txt", "r", stdin);
    freopen("/Users/dreadarceus/github/DSA/Section-5/Quick_Sort/output.txt", "w", stdout);
    srand(time(0));
    int n = 0;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    quickSort(v, 0, n - 1);
    for(int x : v)
    {
        cout << x << " ";
    }
}