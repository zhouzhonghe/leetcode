#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string getAnti(string s) {
    string res = "";
    for (char c : s) {
        if (c == '-') {
            res += '+';
        } else if (c == '+') {
            res += '-';
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    unordered_map<string, int> m;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string code = "";
        int tmp = 0, last = 0;
        for (int j = 0; j < k; ++j) {
            cin >> tmp;
            if (j == 0) {
                last = tmp;
            } else {
                if (tmp > last) {
                    code += '+';
                }
                code += to_string(tmp - last);
            }
        }
        ++m[code];
    }
    int res = 0;
    for (auto it : m) {
        string anti = getAnti(it.first);
        if (anti == it.first) {
            res += (it.second - 1) * it.second;
        } else if (m.count(anti) > 0) {
            res += it.second * m[anti];
        }
    }

    cout << res / 2 << "\n";
    return 0;
}