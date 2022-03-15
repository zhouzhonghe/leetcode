#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0]
的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入
行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格
[35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35,
38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？。
*/

//广度优先
int movingCount(int m, int n, int k)
{
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    queue<vector<int>> q;
    q.push({0, 0});
    int count = 0;
    while (!q.empty()) {
        vector<int> tmp = q.front();
        int i = tmp[0];
        int j = tmp[1];
        int sum = i / 10 + i % 10 + j / 10 + j % 10;
        q.pop();
        if (i < 0 || i >= m || j < 0 || j >= n || sum > k || visited[i][j])
            continue;
        visited[i][j] = 1;
        count++;
        q.push({i + 1, j});
        q.push({i, j + 1});
    }
    return count;
}

//深度优先
//巧妙利用返回值计算
int dfs(int i, int j, int m, int n, int k, vector<vector<bool>> &visited)
{
    int sum = i / 10 + i % 10 + j / 10 + j % 10;
    if (i >= m || j >= n || visited[i][j] || sum > k)
        return 0;
    visited[i][j] = true;
    return 1 + dfs(i + 1, j, m, n, k, visited) +
           dfs(i, j + 1, m, n, k, visited);
}

int movingCount2(int m, int n, int k)
{
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(0, 0, m, n, k, visited);
}