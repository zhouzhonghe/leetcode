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

//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。
//换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
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
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            char cR = s2[i];
            char cL = s2[i - s1.size()];
            if (cR == cL) {
                continue;
            }
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
                return true;
            }
        }
        return false;
    }
};