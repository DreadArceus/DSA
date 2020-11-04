//Literally making a height-width variable sliding window
//and sliding it around every single place it can be in a given matrix
//insanity but kinda slow (passed 35/40 cases)
#include <iostream>
#include <vector>
using namespace std;

int rangeSum(vector<vector<int>> matrix, int x1, int y1, int x2, int y2)
{
    int sum = 0;
    for(int i = x1; i <= x2; i++)
    {
        for(int j = y1; j <= y2; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int solve(vector<vector<int>> matrix, int target)
{
    int cnt = 0;
    for(int k1 = 1; k1 <= matrix.size(); k1++) //Dynamic Window Height
    {
        for(int k2 = 1; k2 <= matrix[0].size(); k2++) //Dynamic Window Width
        {
            int sum = rangeSum(matrix, 0, 0, k1 - 1, k2 - 1); //Initial Window of k1,k2 dimensions
            if(sum == target)
            {
                cnt++;
            }

            for(int i = k2-1; i < matrix[0].size(); i++) //Moving window to the right
            {
                if(i != k2-1)
                {
                    sum += rangeSum(matrix, 0, i, k1-1, i) - rangeSum(matrix, 0, i-k2, k1-1, i-k2);
                    if(sum == target)
                    {
                        cnt++;
                    }
                }

                int localSum = sum;
                for(int j = k1; j < matrix.size(); j++) //Moving window to the bottom
                {
                    localSum += rangeSum(matrix, j, i-k2+1, j, i) - rangeSum(matrix, j-k1, i-k2+1, j-k1, i);
                    if(localSum == target)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n = 0, target = 0;
    cin >> n >> target;
    vector<vector<int>> grid(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x = 0;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    int ans = solve(grid, target);
    cout << ans;
}