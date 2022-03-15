#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> nums(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        nums[s[i] - 'A'] = i;
    }
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        end = max(end, nums[s[i] - 'A']);
        if (i == end) {
            res.emplace_back(end - start + 1);
            start = end + 1;
        }
    }
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}