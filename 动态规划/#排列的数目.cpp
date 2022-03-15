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

/*剑指 Offer II 104
给定一个由 不同 正整数组成的数组 nums ，和一个目标整数 target 。请从 nums 中找出并返回总和为 target
的元素组合的个数。数组中的数字可以在一次排列中出现任意次，但是顺序不同的序列被视作不同的组合。
题目数据保证答案符合 32 位整数范围。
*/
//当x+y<z判断式会越界时，改为x<z-y即可
class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> v(target + 1, 0);
        v[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i && v[i - num] <= INT_MAX - v[i]) {
                    v[i] += v[i - num];
                }
            }
        }
        return v[target];
    }
};