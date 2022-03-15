#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        int time = 0;
        sort(w.begin(), w.end());
        while (n >= 4) {
            time += min(w[n - 1] + w[n - 2] + 2 * w[0], 2 * w[1] + w[0] + w[n - 1]);
            n -= 2;
        }
        if (n == 2) {
            time += w[1];
        } else {
            time += w[0] + w[1] + w[2];
        }
        cout << time << "\n";
    }
    return 0;
}