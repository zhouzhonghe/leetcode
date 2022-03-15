#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int times;
    cin >> times;
    while ((times--) > 0) {
        int n, m;
        cin >> n;
        string used = "";
        cin >> used;
        cin >> m;
        string gender = "";
        cin >> gender;

        priority_queue<int, vector<int>, greater<int>> q0;
        priority_queue<int, vector<int>, greater<int>> q1;
        for (int i = 0; i < n; i++) {
            if (used[i] == '0') {
                q0.push(i);
            } else if (used[i] == '1') {
                q1.push(i);
            }
        }
        int idx_m = 0, idx_f = 0;
        for (int i = 0; i < m; i++) {
            if (gender[i] == 'M') {
                if (!q1.empty()) {
                    int idx = q1.top();
                    cout << idx + 1 << "\n";
                    q1.pop();
                } else {
                    int idx = q0.top();
                    cout << idx + 1 << "\n";
                    q0.pop();
                    q1.push(idx);
                }
            } else {
                if (!q0.empty()) {
                    int idx = q0.top();
                    cout << idx + 1 << "\n";
                    q0.pop();
                    q1.push(idx);
                } else {
                    int idx = q1.top();
                    cout << idx + 1 << "\n";
                    q1.pop();
                }
            }
        }
    }
    return 0;
}