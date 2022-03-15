#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<pair<int, int>> &v, int l, int r) {
    if (l >= r) {
        return;
    }
    int tmp = l;
    int i = l, j = r;
    while (i < j) {
        while (i < j && v[j].first >= v[tmp].first) {
            j--;
        }
        while (i < j && v[i].first <= v[tmp].first) {
            i++;
        }
        swap(v[i], v[j]);
    }
    swap(v[tmp], v[i]);
    quickSort(v, l, i - 1);
    quickSort(v, i + 1, r);
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<pair<int, int>> xy(n);
        for (int i = 0; i < n; ++i) {
            cin >> xy[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> xy[i].second;
        }
        quickSort(xy, 0, n - 1);
        cout << "x: ";
        for (auto x : xy) {
            cout << x.first << " ";
        }
        cout << endl;
        cout << "y: ";
        for (auto x : xy) {
            cout << x.second << " ";
        }
        cout << endl;
        int minNum = 1000000000;
        int Mres = 0;
        for (int i = 0; i < n; ++i) {
            if (xy[i].second >= minNum) {
                continue;
            }
            int res = 1;
            int tmp = i;
            for (int j = i + 1; j < n; ++j) {
                if (xy[j].second > xy[tmp].second && xy[j].first > xy[tmp].first) {
                    int bestIdx = j;
                    int idx = j + 1;
                    while (idx < n && xy[idx].first == xy[j].first) {
                        if (xy[idx].second < xy[bestIdx].second &&
                            xy[idx].second > xy[tmp].second) {
                            bestIdx = idx;
                        }
                        ++idx;
                    }
                    j = idx - 1;
                    ++res;
                    tmp = bestIdx;
                }
            }
            minNum = xy[i].second;
            if (res > Mres) {
                Mres = res;
            }
        }
        cout << Mres << "\n";
    }
    return 0;
}