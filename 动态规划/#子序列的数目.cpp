#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*剑指 Offer II 097
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的
新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。
*/
class Solution {
  public:
    int numDistinct(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        if (lenS < lenT) {
            return 0;
        }
        vector<vector<int>> v(lenS + 1, vector<int>(lenT + 1, 0));
        for (int i = 0; i < lenS + 1; i++) {
            v[i][lenT] = 1;
        }
        for (int i = lenS - 1; i >= 0; i--) {
            for (int j = lenT - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    long long tmp = (long long)(v[i + 1][j + 1]) + (long long)(v[i + 1][j]);
                    if (tmp > INT_MAX) {
                        tmp = INT_MAX;
                    }
                    v[i][j] = tmp;
                } else {
                    v[i][j] = v[i + 1][j];
                }
            }
        }
        return v[0][0];
    }
};
// 创建二维数组 dp，其中 dp[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数。