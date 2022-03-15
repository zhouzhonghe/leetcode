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

class Solution
{
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int sum = 1;
        int res = 0, l = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum *= nums[i];
            if (sum < k) {
                res += i - l + 1;
            } else {
                while (l <= i && sum >= k) {
                    sum /= nums[l];
                    l++;
                }
                res += i - l + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> v{10, 5, 2, 6};
    int res = so.numSubarrayProductLessThanK(v, 100);
    cout << res << endl;
}