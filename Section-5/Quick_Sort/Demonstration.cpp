//v1
//My first implementation of quick sort.
//The way i moved elements around the pivot seems to take too much time.
//Hence this is not a good enough quick sort implementation
#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> v, int start, int end)
{
    if(start >= end - 1)
    {
        return v;
    }

    int pivot = (end + start)/2;

    for(int i = start; i < pivot; i++)
    {
        auto it_current = v.begin() + i;
        if(*it_current > *(v.begin() + pivot))
        {
            int x = *(v.begin() + i);
            v.erase(it_current);
            pivot--;
            v.insert(v.begin() + pivot + 1, x);
            i--;
        }
    }

    for(int i = pivot + 1; i < end; i++)
    {
        auto it_current = v.begin() + i;
        if(*it_current < *(v.begin() + pivot))
        {
            int x = *(v.begin() + i);
            v.erase(it_current);
            v.insert(v.begin() + pivot, x);
            pivot++;
            i--;
        }
    }

    v = quickSort(v, start, pivot);

    v = quickSort(v, pivot + 1, end);

    return v;
}

int main()
{
    freopen("/Users/dreadarceus/github/DSA/Section-5/Quick_Sort/inp.txt", "r", stdin);
    int n = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    v = quickSort(v, 0, n);
    for(int x : v)
    {
        cout << x << " ";
    }
}