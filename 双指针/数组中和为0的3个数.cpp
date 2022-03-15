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

//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c
//，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3) {
            return {};
        }
        recur(nums, 0, nums.size() - 1);
        vector<vector<int>> res;
        int i = 0;
        while (i < nums.size() - 2 && nums[i] <= 0) {
            int l = i + 1, r = nums.size() - 1;
            int target = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (nums[l] + nums[r] < -nums[i]) {
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } else {
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
            i++;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return res;
    }

    void recur(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int tmp = nums[l];
        int i = l, j = r; //为防止所有数都比基数大，左指针从基数开始
        while (i < j) {
            while (i < j && nums[j] >= tmp) //因为选择左端为基数，所以先向左循环
                j--;
            while (i < j &&
                   nums[i] <= tmp) //为防止左指针不动，必须用大于等于判断
                i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        recur(nums, l, i - 1);
        recur(nums, i + 1, r);
    }
};