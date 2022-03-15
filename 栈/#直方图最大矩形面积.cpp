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

/*
给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。
每个柱子彼此相邻，且宽度为 1。求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

//出栈即可算出该高度对应的最大面积
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? heights.size() : heights.size() - s.top() - 1;
                res = max(res, height * width);
            }
            s.push(i);
        }
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? heights.size() : heights.size() - s.top() - 1;
            res = max(res, height * width);
        }
        return res;
    }
};