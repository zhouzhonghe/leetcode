#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k);

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> maxs;
    if (nums.size() == 0)
        return maxs;
    vector<int> tmp;
    int max = nums[0];
    for (int i = 1; i < k; i++) {
        if (nums[i] > max)
            max = nums[i];
    }
    maxs.push_back(max);
    for (int i = 1; i < nums.size() - k + 1; i++) {
        if (nums[i - 1] == max) {
            max = nums[i];
            for (int j = i; j < i + k; j++) {
                if (nums[j] > max)
                    max = nums[j];
            }
        } else if (nums[i + k - 1] > max)
            max = nums[i + k - 1];
        maxs.push_back(max);
    }
    return maxs;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    vector<int> maxs = maxSlidingWindow(nums, 3);
    for (int i = 0; i < maxs.size(); i++)
        cout << maxs[i] << endl;
    cout << maxs.size();
}