#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1
必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
*/
class Solution {
  public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !visited[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = false;
        return 1 + dfs(i + 1, j, grid, visited) + dfs(i, j + 1, grid, visited) +
               dfs(i, j - 1, grid, visited) + dfs(i - 1, j, grid, visited);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), true));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int x = dfs(i, j, grid, visited);
                res = max(res, x);
            }
        }
        return res;
    }
};