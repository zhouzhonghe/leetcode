#include <iostream>
#include <set>
#include <vector>

using namespace std;
void recur(int target, int step, int &res, int nums) {
    if (nums >= 10000) {
        return;
    }
    if (target == 0) {
        res = max(res, nums);
        return;
    }
    target -= step;
    step++;
    nums++;
    if (target < 0) {
        recur(target, -step, res, nums);
    } else {
        recur(target, -step, res, nums);
        recur(target, step, res, nums);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<int> res;
    int target = 0, cur = 0, nums = 0;
    for (int xi : x) {
        target = xi - cur;
        cur = xi;
        int step = 1;
        int re = 0;
        recur(target, 1, re, 0);
        res.push_back(re);
    }
    for (int x : res) {
        cout << x << endl;
    }
    return 0;
}