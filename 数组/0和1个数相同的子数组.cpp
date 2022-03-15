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

//给定一个二进制数组 nums , 找到含有相同数量的 0 和 1
//的最长连续子数组，并返回该子数组的长度。
class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        int res = 0;
        int dis = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            dis += (nums[i] == 1) ? 1 : -1;
            if (map.count(dis)) {
                res = max(res, i - map[dis]);
            } else {
                map[dis] = i;
            }
        }
        return res;
    }
};