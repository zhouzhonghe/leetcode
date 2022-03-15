#include <iostream>
#include <set>
#include <vector>

using namespace std;

void recur(vector<vector<int>> W, vector<vector<bool>> &visited, int M, int i, int j, int nums,
           int &res) {
    if (i < 0 || j < 0 || i >= W.size() || j >= W.size()) {
        return;
    }
    if (!visited[i][j]) {
        ++nums;
        M -= W[i][j];
        if (M < 0 || (M == 0 && i != 0 && i != W.size() - 1 && j != 0 && j != W.size() - 1)) {
            return;
        }
        if (M == 0) {
            res = max(res, nums);
            return;
        }
        visited[i][j] = true;
        recur(W, visited, M, i + 1, j, nums, res);
        recur(W, visited, M, i - 1, j, nums, res);
        recur(W, visited, M, i, j + 1, nums, res);
        recur(W, visited, M, i, j - 1, nums, res);
        visited[i][j] = false;
    }
}

int main() {
    int M = 30, L = 5;
    vector<vector<int>> W{
        {1, 2, 3, 4, 5}, {5, 2, 2, 9, 3}, {1, 8, 5, 7, 2}, {2, 1, 1, 2, 4}, {1, 4, 7, 9, 1}};
    vector<vector<bool>> visited(L, vector<bool>(L, false));
    int res = 0;
    recur(W, visited, M, 0, 0, 0, res);
    cout << res << endl;
}