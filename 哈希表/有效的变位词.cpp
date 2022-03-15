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
给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。
注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和
t 互为变位词（字母异位词）。
*/
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() == 1 || t.size() == 1 || s.size() != t.size()) {
            return false;
        }
        vector<int> v(26, 0);
        for (char c : s) {
            v[c - 'a']++;
        }
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (!flag && t[i] != s[i]) {
                flag = true;
            }
            if (v[t[i] - 'a'] == 0) {
                return false;
            }
            v[t[i] - 'a']--;
        }
        return flag ? true : false;
    }
};