#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        stack<char> s1;
        for (char c : str) {
            if (s1.empty() || c >= s1.top()) {
                s1.push(c);
            } else {
                while (!s1.empty() && c < s1.top() && m > 0) {
                    s1.pop();
                    --m;
                }
                s1.push(c);
            }
        }
        while (m-- > 0) {
            s1.pop();
        }
        stack<char> s2;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        string res2 = "";
        while (!s2.empty()) {
            res2 += s2.top();
            s2.pop();
        }
        cout << res2 << endl;
    }
    return 0;
}