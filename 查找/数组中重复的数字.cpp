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

int findRepeatNumber(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) != m.end())
            return nums[i];
        else
            m[nums[i]] = i;
    }
    return -1;
}