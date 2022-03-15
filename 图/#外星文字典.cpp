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

/*剑指 Offer II 114
现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了
排序。请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，
返回 ""。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
字符串 s 字典顺序小于 字符串 t 有两种情况：
在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s
的字典顺序小于 t 。 如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，
s的字典顺序也小于 t 。
*/
// 1. 只需相邻比较，不需要双重循环比较
// 2. 需要记载每个字符的入度
class Solution {
  public:
    string alienOrder(vector<string> &words) {
        unordered_map<char, vector<char>> graph;
        vector<int> num(26, 0);
        string res = "";
        queue<char> q;
        for (string word : words) {
            for (char c : word) {
                graph[c] = {};
            }
        }
        for (int i = 1; i < words.size(); i++) {
            string s1 = words[i - 1], s2 = words[i];
            bool flag = true;
            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    graph[s1[j]].push_back(s2[j]);
                    num[s2[j] - 'a']++;
                    flag = false;
                    break;
                }
            }
            if (flag && s1.size() > s2.size()) {
                return "";
            }
        }
        for (auto it = graph.begin(); it != graph.end(); it++) {
            if (num[it->first - 'a'] == 0) {
                q.push(it->first);
            }
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            for (char x : graph[c]) {
                num[x - 'a']--;
                if (num[x - 'a'] == 0) {
                    q.push(x);
                }
            }
        }
        if (res.size() == graph.size()) {
            return res;
        } else {
            return "";
        }
    }
};