//v3
//Readability upgrade
#include <iostream>
#include <random>
using namespace std;

//utility swap function (also in <algortihm>)
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//this function partitions the subarray around a random pivot
int partitioner(int v[], int start, int end)
{
    int pivot = rand() % (end - start + 1) + start;
    int pivot_value = v[pivot];
    swap(v[pivot], v[end]);
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
        swap(v[l], v[r]);
        pivot = r;
    }
    swap(v[pivot], v[end]);
    return pivot;
}

//recursive function for quick sort
void quickSort(int v[], int start, int end)
{
    if(start < end)
    {
        int pivot = partitioner(v, start, end);
        quickSort(v, start, pivot - 1);
        quickSort(v, pivot + 1, end);
    }
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