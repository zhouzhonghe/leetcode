#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> m(3, vector<long long>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 3; ++i) {
            dp[i][j] = min(dp[0][j - 1] + abs(m[0][j - 1] - m[i][j]),
                           min(dp[1][j - 1] + abs(m[1][j - 1] - m[i][j]),
                               dp[2][j - 1] + abs(m[2][j - 1] - m[i][j])));
        }
    }
    long long res = min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
    cout << res << "\n";
    return 0;
}