#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*给定一个二维矩阵 matrix，以下类型的多个请求：
计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
实现 NumMatrix 类：
NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回左上角 (row1, col1) 、
右下角 (row2, col2) 的子矩阵的元素总和。
*/

class NumMatrix {
  public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        mat.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] += matrix[i][j];
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        res += mat[row2][col2];
        if (row1 > 0) {
            res -= mat[row1 - 1][col2];
        }
        if (col1 > 0) {
            res -= mat[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            res += mat[row1 - 1][col1 - 1];
        }
        return res;
    }

  private:
    vector<vector<int>> mat;
};