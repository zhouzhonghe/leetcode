#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> res(n);
    int l = 0, r = n / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            res[i] = a[r++];
        } else {
            res[i] = a[l++];
        }
        if (i >= 1) {
            sum += abs(res[i] - res[i - 1]);
        }
    }
    sum += abs(res[0] - res[n - 1]);
    cout << sum << "\n";
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}