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

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串 的长度。
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> map;
        int l = 0;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) && map[s[i]] >= l) {
                l = map[s[i]] + 1;
            }
            map[s[i]] = i;
            res = max(res, i - l + 1);
        }
        return res;
    }
};