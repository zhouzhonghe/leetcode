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

//给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k
//小的元素。请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int m = l + (r - l) / 2;
            int i = n - 1, j = 0;
            int nums = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= m) {
                    nums += i + 1;
                    j++;
                } else {
                    i--;
                }
            }
            if (nums >= k - 1) {
                r = m;
            } else {
                l = m + 1; //迭代必须用加法，减法会导致无限循环，因为相除-1
            }
        }
        return l;
    }
};