#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
        return false;
    int i = 0, j = matrix[0].size() - 1;
    while (j >= 0 && i < matrix.size()) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

int main() {
    vector<vector<int>> nums{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
    bool res = findNumberIn2DArray(nums, 15);
    cout << res << endl;
}