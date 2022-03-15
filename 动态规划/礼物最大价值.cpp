#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int maxValue(vector<vector<int>> &grid);

int maxValue(vector<vector<int>> &grid)
{
    int i = 0, j = 0;
    for (i = 0; i < grid.size(); i++) {
        for (j = 0; j < grid[i].size(); j++) {
            if (i == 0 && j != 0)
                grid[i][j] += grid[i][j - 1];
            else if (i != 0 && j == 0)
                grid[i][j] += grid[i - 1][j];
            else if (i != 0 && j != 0)
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[i - 1][j - 1];
}
int main()
{
    // int x = maxValue();
}