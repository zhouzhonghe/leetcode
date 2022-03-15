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

int missingNumber(vector<int> &nums) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] <= m)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {
    vector<int> v{0, 1, 2, 3, 4, 6};
    int res = missingNumber(v);
    cout << res << endl;
}