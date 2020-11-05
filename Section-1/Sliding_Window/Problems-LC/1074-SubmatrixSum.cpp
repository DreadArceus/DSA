//Second attempt, preprocessing some Prefix Sum arrays this time
//Faster than the last one ofc, but still slower than needed (40/40 cases passed but took too long)
//O(N^2 * M^2) or O(N^4) down from O(N^5)
//From discussions, it seems changing the whole approach from 
//  sliding window can make a passable O(N^4) solution
//Thats coming up next
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> rowPS(n, vector<int>(m, 0));
    vector<vector<int>> columnPS(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        rowPS[i][0] = matrix[i][0];
        for(int j = 1; j < m; j++)
        {
            rowPS[i][j] = rowPS[i][j-1] + matrix[i][j];
        }
    }
    for(int j = 0; j < m; j++)
    {
        columnPS[0][j] = matrix[0][j];
        for(int i = 1; i < n; i++)
        {
            columnPS[i][j] = columnPS[i-1][j] + matrix[i][j];
        }
    }

    int cnt = 0;
    for(int k1 = 1; k1 <= n; k1++) //Dynamic Window Height
    {
        for(int k2 = 1; k2 <= m; k2++) //Dynamic Window Width
        {
            //Initial Window of k1,k2 dimensions
            int sum = 0;
            for(int i = 0; i < k1; i++)
            {
                for(int j = 0; j < k2; j++)
                {
                    sum += matrix[i][j];
                }
            }
            if(sum == target)
            {
                cnt++;
            }

            for(int i = k2-1; i < m; i++) //Moving window to the right
            {
                if(i != k2-1)
                {
                    sum += columnPS[k1-1][i] - columnPS[k1-1][i-k2];
                    if(sum == target)
                    {
                        cnt++;
                    }
                }
                int localSum = sum;
                for(int j = k1; j < n; j++) //Moving window to the bottom
                {
                    localSum += (rowPS[j][i] - ((i!=k2-1) ? rowPS[j][i-k2] : 0)) - (rowPS[j-k1][i] - ((i!=k2-1) ? rowPS[j-k1][i-k2] : 0));
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
    int n = 0, m = 0, target = 0;
    cin >> n >> m >> target;
    vector<vector<int>> grid(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x = 0;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    int ans = solve(grid, target);
    cout << ans;
}