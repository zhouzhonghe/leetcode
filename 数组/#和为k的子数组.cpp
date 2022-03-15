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

//给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。
//前缀和
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int num : nums) {
            sum += num;
            res += map[sum - k];
            map[sum] += 1;
        }
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> v{1, -1, 0};
    int res = so.subarraySum(v, 0);
    cout << res << endl;
}