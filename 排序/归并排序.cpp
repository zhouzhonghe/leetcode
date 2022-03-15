#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> nums);
void recur(vector<int> &nums, int l, int r);

vector<int> mergeSort(vector<int> nums)
{
    recur(nums, 0, nums.size() - 1);
    return nums;
}

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
int main()
{
    vector<int> nums{10, 2, 4, 6, 3, 7, 9, 8};
    nums = mergeSort(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}