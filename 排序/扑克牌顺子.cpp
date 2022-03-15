#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void recur(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    recur(nums, l, m);
    recur(nums, m + 1, r);
    vector<int> tmp(r - l + 1);
    int i = l, j = m + 1;
    for (int k = 0; k <= r - l; k++) {
        if (i > m)
            tmp[k] = nums[j++];
        else if (j > r || nums[i] <= nums[j]) //判断顺序很重要，防止j已经越界
            tmp[k] = nums[i++];
        else
            tmp[k] = nums[j++];
    }
    for (int k = 0; k <= r - l; k++)
        nums[l + k] = tmp[k];
}

bool isStraight(vector<int> &nums)
{
    recur(nums, 0, nums.size() - 1);
    int king = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            king++;
        } else {
            if (i < nums.size() - 1) {
                if (nums[i] == nums[i + 1])
                    return false;
                king -= nums[i + 1] - nums[i] - 1;
            }
            if (king < 0)
                return false;
        }
    }
    return true;
}