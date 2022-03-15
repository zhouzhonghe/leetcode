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

/*剑指 Offer II 115
请判断原始的序列 org 是否可以从序列集 seqs 中唯一地 重建 。
序列 org 是 1 到 n 整数的排列，其中 1 ≤ n ≤ 104。重建 是指在序列集 seqs
中构建最短的公共超序列，即  seqs 中的任意序列都是该最短序列的子序列。
*/
class Solution {
  public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        //检查元素及数量是否一致
        set<int> s;
        for (auto seq : seqs) {
            for (int x : seq) {
                s.insert(x);
            }
        }
        if (s.size() != org.size()) {
            return false;
        }
        for (int x : org) {
            if (s.count(x) == 0) {
                return false;
            }
        }

        //构建拓扑
        unordered_map<int, set<int>> graph;
        for (int i = 1; i <= org.size(); i++) {
            graph[i] = {};
        }
        vector<int> num(org.size() + 1, 0);
        for (auto seq : seqs) {
            for (int i = 1; i < seq.size(); i++) {
                if (graph[seq[i - 1]].count(seq[i]) == 0) {
                    graph[seq[i - 1]].insert(seq[i]);
                    num[seq[i]]++;
                }
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == 0) {
                q.push(i);
            }
        }

        //拓扑排序输出
        while (!q.empty()) {
            if (q.size() != 1) {
                return false;
            }
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int next : graph[x]) {
                num[next]--;
                if (num[next] == 0) {
                    q.push(next);
                }
            }
        }
        //验证是否一致
        if (res.size() != org.size()) {
            return false;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != org[i]) {
                return false;
            }
        }
        return true;
    }
};