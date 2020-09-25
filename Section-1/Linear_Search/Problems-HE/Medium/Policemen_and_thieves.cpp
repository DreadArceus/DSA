//Partial solution, need to optimise the search through the grid
//Hint: single traversal through rows?? be back -10-September-2020
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<vector<char>> grid, int k)
{
    int cnt = 0, n = grid.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 'P')
            {
                for(int z = j - k; z <= j + k; z++)
                {
                    if(z >= 0 && z < n && grid[i][z] == 'T')
                    {
                        cnt++;
                        grid[i][z] = 0;
                        break;
                    }
                }
            }
        }
    }
    return cnt;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<vector<char>> grid(n);
        for(int i = 0; i < n; i++)
        {
            vector<char> loc(n);
            for(int j = 0; j < n; j++)
            {
                cin >> loc[j];
            }
            grid[i] = loc;
        }
        int ans = solve(grid, k);
        cout << ans << "\n";
    }
}