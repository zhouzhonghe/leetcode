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

vector<int> exchange(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l] % 2 == 0 && nums[r] % 2 != 0) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        } else {
            if (nums[l] % 2 != 0)
                l++;
            if (nums[r] % 2 == 0)
                r--;
        }
    }
    return nums;
}