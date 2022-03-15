#include <iostream>
#include <set>
#include <vector>

using namespace std;

void recur(vector<vector<int>> v, vector<bool> &ordered, vector<bool> p, int &res, int nums,
           int times) {

    if (times == v.size()) {
        res = max(res, nums);
        return;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (p[i]) {
            if (v[i][0] < ordered.size() && v[i][1] < ordered.size() && ordered[v[i][0]] &&
                ordered[v[i][1]]) {
                ordered[v[i][0]] = false;
                ordered[v[i][1]] = false;
                p[i] = false;
                recur(v, ordered, p, res, nums + 1, times + 1);
                p[i] = true;
                ordered[v[i][0]] = true;
                ordered[v[i][1]] = true;
            } else {
                ++times;
                p[i] = false;
            }
        }
    }
}

int main() {
    int n = 8, m = 12;
    vector<bool> ordered(m + 1, true);
    vector<bool> p(m, true);
    vector<vector<int>> v{{3, 9}, {8, 9}, {5, 1}, {5, 11}, {8, 2}, {11, 7}, {11, 6}, {7, 10}};
    int res = 0;
    recur(v, ordered, p, res, 0, 0);
    cout << res << endl;
    return 0;
}