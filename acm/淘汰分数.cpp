#include <iostream>
#include <vector>
using namespace std;
void recur(vector<int> &nums, int l, int r) {
    if (l >= r)
        return;
    int tmp = nums[l];
    int i = l, j = r; //为防止所有数都比基数大，左指针从基数开始
    while (i < j) {
        while (i < j && nums[j] >= tmp) //因为选择左端为基数，所以先向左循环
            j--;
        while (i < j && nums[i] <= tmp) //为防止左指针不动，必须用大于等于判断
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    recur(nums, l, i - 1);
    recur(nums, i + 1, r);
}
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> score(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    int l = max(n - y, x), r = min(n - x, y);
    if (l > r) {
        cout << -1 << endl;
        return 0;
    }
    recur(score, 0, n - 1);
    for (int i = l - 1; i < r; i++) {
        if (score[i] != score[i + 1]) {
            cout << score[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}