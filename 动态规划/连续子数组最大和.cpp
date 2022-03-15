#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums);

int maxSubArray(vector<int> &nums)
{
    int m = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > 0)
            nums[i] += nums[i - 1];
        if (nums[i] > m)
            m = nums[i];
    }
    return m;
}
int main()
{
    vector<int> b;
    b.push_back(1);
    b.push_back(-2);
    b.push_back(3);
    b.push_back(-2);
    b.push_back(5);
    // b.push_back(2);
    int m = maxSubArray(b);
    cout << m;
}