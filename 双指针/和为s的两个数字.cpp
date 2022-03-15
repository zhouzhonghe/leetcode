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

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                return {l, r};
            else if (numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {0, 0};
    }
};

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l] + nums[r] == target)
            return {nums[l], nums[r]};
        else if (nums[l] + nums[r] > target)
            r--;
        else
            l++;
    }
    return {};
}