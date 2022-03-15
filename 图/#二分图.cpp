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

/*剑指 Offer II 106
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
给定一个二维数组 graph ，表示图，其中 graph[u] 是一个节点数组，由节点 u
的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v
之间的无向边。该无向图同时具有以下属性：
不存在自环（graph[u] 不包含 u）。
不存在平行边（graph[u] 不包含重复值）。
如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B
，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。
如果图是二分图，返回 true ；否则，返回 false 。
*/
//思路：给每个结点涂色，相邻不同
class Solution {
  private:
    vector<int> color;

  public:
    bool dfs(int i, vector<vector<int>> &graph, int c) {
        if (color[i] == -c) {
            return true;
        }
        if (color[i] == c) {
            return false;
        }
        color[i] = -c;
        bool res = true;
        for (int k = 0; k < graph[i].size(); k++) {
            res &= dfs(graph[i][k], graph, color[i]);
        }
        return res;
    }
    bool isBipartite(vector<vector<int>> &graph) {
        color.resize(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() > 0 && color[i] == 0) {
                if (!dfs(i, graph, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};