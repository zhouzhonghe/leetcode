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
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标
相同或者等于上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，
那么下一步可以移动到下一行的下标i 或 i + 1 。
*/
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        int idx = triangle.size() - 1;
        int res = INT_MAX;
        for (int i = 0; i < triangle[idx].size(); i++) {
            if (triangle[idx][i] < res) {
                res = triangle[idx][i];
            }
        }
        return res;
    }
};