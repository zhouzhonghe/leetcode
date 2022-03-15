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

int search(vector<int> &nums, int target) {
    if (nums.size() == 0)
        return 0;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] >= target)
            r = m;
        else
            l = m + 1;
    }
    if (nums[l] != target)
        return 0;
    int sum = 0;
    for (int i = l; i < nums.size(); i++)
        if (nums[i] == target)
            sum++;
    for (int i = l; i >= 0; i--)
        if (nums[i] == target)
            sum++;
    return sum - 1;
}