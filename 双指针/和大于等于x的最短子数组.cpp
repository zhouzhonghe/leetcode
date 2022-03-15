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

/*给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 
    [numsl, numsl + 1, ..., numsr - 1,
     numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
     */
class Solution
{
  public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX;
        int sum = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= target) {
                while (sum >= target) {
                    sum -= nums[l];
                    l++;
                }
                l--;
                sum += nums[l];
                res = min(res, i - l + 1);
            }
        }
        if (res == INT_MAX) {
            res = 0;
        }
        return res;
    }
};