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
    for (int k = l; k <= r; k++)
        tmp[k - l] = nums[k];
    int i = 0, j = m - l + 1;
    for (int k = l; k <= r; k++) {
        if (i > m - l)
            nums[k] = tmp[j++];
        else if (j > r - l || ((to_string(tmp[i]) + to_string(tmp[j])) <=
                               (to_string(tmp[j]) + to_string(tmp[i]))))
            nums[k] = tmp[i++];
        else
            nums[k] = tmp[j++];
    }
}

string minNumber(vector<int> &nums)
{
    recur(nums, 0, nums.size() - 1);
    string s;
    for (auto x : nums)
        s += to_string(x);
    return s;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(30);
    v.push_back(34);
    v.push_back(5);
    v.push_back(9);
    string s = minNumber(v);
    cout << s << endl;
}