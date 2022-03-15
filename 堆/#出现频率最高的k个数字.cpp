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

/*剑指 Offer II 060
给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
*/
class Solution {
  private:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int x : nums) {
            map[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.emplace(it->first, it->second);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};