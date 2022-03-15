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

class Solution
{
  public:
    int maxProduct(vector<string> &words)
    {
        map<int, int> m;
        vector<int> bitMask(words.size());
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (auto c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            if (m.count(mask)) {
                m[mask] = max(m[mask], (int)words[i].size());
            } else {
                m[mask] = words[i].size();
            }
        }
        int res = 0;
        for (auto x : m) { //提取迭代器从而获得key值
            for (auto y : m) {
                if ((x.first & y.first) == 0) {
                    res = max(res, x.second * y.second);
                }
            }
        }
        return res;
    }
};