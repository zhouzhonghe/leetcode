#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。
如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
如果 s 中存在多个符合条件的子字符串，返回任意一个。
*/
class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> nums;
        int diff = 0;
        for (int i = 0; i < t.size(); i++) {
            if (nums.count(t[i])) {
                nums[t[i]]++;
            } else {
                nums[t[i]] = 1;
                diff++;
            }
        }
        int len = INT_MAX;
        string res = "";
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (nums.count(s[r])) {
                nums[s[r]]--;
                if (nums[s[r]] == 0) {
                    diff--;
                }
                if (diff == 0) {
                    while (true) {
                        if (!nums.count(s[l])) {
                            l++;
                        } else if (nums[s[l]] < 0) {
                            nums[s[l]]++;
                            l++;
                        } else {
                            break;
                        }
                    }
                    if (r - l + 1 < len) {
                        len = r - l + 1;
                        res = s.substr(l, len);
                    }
                    nums[s[l]]++;
                    diff++;
                    l++;
                }
            }
        }
        return res;
    }
};