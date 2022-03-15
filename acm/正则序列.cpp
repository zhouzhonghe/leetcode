#include <iostream>
#include <set>
#include <vector>

using namespace std;

void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int tmp = nums[l];
    int i = l, j = r;
    while (l < r) {
        while (r > l && nums[r] >= tmp) {
            r--;
        }
        while (l < r && nums[l] <= tmp) {
            l++;
        }
        swap(nums[l], nums[r]);
    }
    swap(nums[i], nums[l]);
    quickSort(nums, i, l - 1);
    quickSort(nums, l + 1, j);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    quickSort(nums, 0, n - 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += abs(i - nums[i - 1]);
    }
    cout << res << endl;
    return 0;
}