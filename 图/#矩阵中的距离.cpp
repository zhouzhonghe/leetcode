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

/*剑指 Offer II 107
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat
中对应位置元素到最近的 0 的距离。两个相邻元素间的距离为 1 。
*/
class Solution {
  public:
    //对角线双向dp
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] != 0) {
                    if (i == 0 && j == 0) {
                        if (mat[i][j] == 1) {
                            mat[i][j] = mat.size() + mat[0].size(); //防止开始出错
                        }
                        continue;
                    } else if (i == 0) {
                        mat[i][j] = mat[i][j - 1] + 1;
                    } else if (j == 0) {
                        mat[i][j] = mat[i - 1][j] + 1;
                    } else {
                        mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + 1;
                    }
                }
            }
        }
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat[0].size(); j >= 0; j--) {
                if (mat[i][j] != 0) {
                    if (i == mat.size() - 1 && j == mat[0].size() - 1) {
                        continue;
                    } else if (i == mat.size() - 1) {
                        mat[i][j] = min(mat[i][j], mat[i][j + 1] + 1);
                    } else if (j == mat[0].size() - 1) {
                        mat[i][j] = min(mat[i][j], mat[i + 1][j] + 1);
                    } else {
                        mat[i][j] = min(mat[i][j], min(mat[i][j + 1], mat[i + 1][j]) + 1);
                    }
                }
            }
        }
        return mat;
    }
    //逆向思维，与其一个个点赋值，不如从0点开始向四周赋值
    vector<vector<int>> updateMatrix2(vector<vector<int>> &mat) {
        vector<vector<int>> dists(mat.size(), vector<int>(mat[0].size()));
        queue<pair<int, int>> que;
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    dists[i][j] = 0;
                    que.push({i, j});
                } else {
                    dists[i][j] = INT_MAX;
                }
            }
        }

        while (!que.empty()) {
            auto pos = que.front();
            que.pop();
            int dist = dists[pos.first][pos.second];

            for (auto &d : dirs) {
                int r = pos.first + d[0];
                int c = pos.second + d[1];
                if (r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size()) {
                    if (dist + 1 < dists[r][c]) {
                        dists[r][c] = dist + 1;
                        que.push({r, c});
                    }
                }
            }
        }
        return dists;
    }
};