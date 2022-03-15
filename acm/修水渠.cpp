#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    int y;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y;
    }
    sort(x.begin(), x.end());
    int sum = 0;
    int loc = x[0];
    for (int n : x) {
        sum += n - loc;
    }
    int flag = 1;
    int res = sum;
    for (int i = x[0] + 1; i <= x[n - 1]; ++i) {
        if (i > x[flag]) {
            ++flag;
        }
        if (2 * flag - n > 0) {
            break;
        }
        sum = sum + 2 * flag - n;
        res = min(res, sum);
    }
    cout << res << "\n";
    return 0;
}