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

//给定两个字符串 s 和 p，找到 s 中所有 p
//的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//变位词 指字母相同，但排列不同的字符串。
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        string s1 = p, s2 = s;
        vector<int> res;
        if (s1.size() > s2.size()) {
            return res;
        }
        vector<int> nums(26, 0);
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            nums[s1[i] - 'a']++;
            nums[s2[i] - 'a']--;
        }
        for (int x : nums) {
            if (x != 0) {
                diff++;
            }
        }
        if (diff == 0) {
            res.push_back(0);
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            char cR = s2[i];
            char cL = s2[i - s1.size()];
            if (nums[cR - 'a'] == 0) {
                diff++;
            }
            nums[cR - 'a']--;
            if (nums[cR - 'a'] == 0) {
                diff--;
            }
            if (nums[cL - 'a'] == 0) {
                diff++;
            }
            nums[cL - 'a']++;
            if (nums[cL - 'a'] == 0) {
                diff--;
            }
            if (diff == 0) {
                res.push_back(i - s1.size() + 1);
            }
        }
        return res;
    }
};