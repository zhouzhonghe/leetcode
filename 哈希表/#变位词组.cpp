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
给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。
注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。
*/
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string ori = s;
            sort(s.begin(), s.end());
            if (m.count(s)) {
                m[s].push_back(ori);
            } else {
                m[s] = {ori};
            }
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};