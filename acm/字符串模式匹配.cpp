#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool check(string p, string t) {
    if (p == "" && t == "") {
        return true;
    } else if (p == "") {
        return false;
    } else if (t == "") {
        if (p[0] == '*') {
            string subp = p.size() > 1 ? p.substr(1, p.size() - 1) : "";
            return check(subp, "");
        } else {
            return false;
        }
    } else if (p[0] == t[0] || p[0] == '?') {
        string subp = p.size() > 1 ? p.substr(1, p.size() - 1) : "";
        string subt = t.size() > 1 ? t.substr(1, t.size() - 1) : "";
        return check(subp, subt);
    } else if (p[0] != '*') {
        return false;
    } else {
        if (p.size() == 1) {
            return true;
        }
        int ip = 1;
        char next = NULL;
        while (ip < p.size()) {
            if (p[ip] != '*') {
                next = p[ip];
                break;
            }
            ++ip;
        }
        bool res = false;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == next || next == '?') {
                res |= check(p.substr(1, p.size() - 1), t.substr(i, t.size() - i));
            }
        }
        return res;
    }
}

int main() {
    string p, t;
    cin >> p >> t;
    vector<vector<bool>> dp(p.size() + 1, vector<bool>(t.size() + 1, false));
    dp[0][0] = true;
    int i = 0;
    while (p[i++] == '*') {
        dp[i][0] = true;
    }
    for (int i = 1; i <= p.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if (p[i - 1] == t[j - 1] || p[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[i - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }

    if (dp[p.size()][t.size()]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}