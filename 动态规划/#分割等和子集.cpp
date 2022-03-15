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

/*剑指 Offer II 101
给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。
*/
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((sum & 1) == 1) {
            return false;
        }
        int target = sum >> 1;
        // vector<vector<bool>> v(nums.size() + 1, vector<bool>(target + 1, false));
        // v[0][0] = true;
        // for (int i = 1; i <= nums.size(); i++) {
        //     for (int j = 0; j <= target; j++) {
        //         v[i][j] = v[i - 1][j];
        //         if (!v[i][j] && j >= nums[i - 1]) {
        //             v[i][j] = v[i - 1][j - nums[i - 1]];
        //         }
        //     }
        // }
        vector<bool> v(target + 1, false);
        v[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = target; j >= nums[i - 1]; j--) {
                v[j] = v[j] || v[j - nums[i - 1]];
            }
        }
        return v[target];
    }
};
/*
设 f(i, j) 表示能否从前 i 个物品(物品编号为 0 ~ i - 1)中选择若干物品放满容量为 j 的背包。
对于 f(i,j) 存在两个选择，第一个选择是将标号为 i - 1 的物品放入背包，如果能从前 i - 1
个物品中选择若干物品放满容量为 j - nums[i - 1] 的背包(即 f(i - 1, j - nums[i - 1]) 为 true)，
那么f(i, j) 为 true。另一个选择是不把标号为 i - 1 的物品放入背包，如果能从前 i - 1
个物品中选择若干物品放满容量为 j 的背包(即 f(i - 1, j) 为 true)，那么 f(i, j) 为 true。
*/