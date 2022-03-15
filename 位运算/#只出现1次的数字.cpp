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

//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
//。请你找出并返回那个只出现了一次的元素。
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int twos = 0, ones = 0;
        for (int num : nums) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};