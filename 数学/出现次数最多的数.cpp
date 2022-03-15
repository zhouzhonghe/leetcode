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

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//摩尔投票法
int majorityElement(vector<int> &nums)
{
    int x = 0, volts = 0;
    for (auto num : nums) {
        if (volts == 0)
            x = num;
        volts += num == x ? 1 : -1;
    }
    return x;
}