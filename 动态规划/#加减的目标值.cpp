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

/*剑指 Offer II 102
给定一个正整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1"
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (target > sum) {
            return 0;
        }
        vector<vector<int>> v(nums.size() + 1, vector<int>(2 * sum + 1, 0));
        v[0][sum] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = -sum; j <= sum; j++) {
                if (j - nums[i - 1] >= -sum) {
                    v[i][j + sum] += v[i - 1][j - nums[i - 1] + sum];
                }
                if (j + nums[i - 1] <= sum) {
                    v[i][j + sum] += v[i - 1][j + nums[i - 1] + sum];
                }
            }
        }
        return v[nums.size()][target + sum];
    }
    //巧妙转化成背包问题
    int findTargetSumWays2(vector<int> &nums, int target) {
        int sum = 0;
        for (int &num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int &num : nums) {
            for (int j = neg; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};