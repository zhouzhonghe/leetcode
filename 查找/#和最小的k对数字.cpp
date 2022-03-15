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

/*剑指 Offer II 061
给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
*/
class Solution {
  public:
    struct node {
        int i, j;
        int x, y;
        node(int i, int j, int x, int y) : i(i), j(j), x(x), y(y) {}
        bool operator<(const node &a) const {
            return x + y > a.x + a.y; //小顶堆
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        /*两种方法构建优先队列
        auto cmp = [&](const pair<int, int> &m, const pair<int, int> &n) {
            return (nums1[m.first] + nums2[m.second]) > (nums1[n.first] + nums2[n.second]);
        };
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        */
        priority_queue<node> pq;
        for (int i = 0; i < min(k, m); i++) {
            node tmp(i, 0, nums1[i], nums2[0]);
            pq.push(tmp);
        }
        while (k-- > 0 && !pq.empty()) {
            node tmp = pq.top();
            pq.pop();
            ans.push_back({tmp.x, tmp.y});
            if (tmp.j + 1 < n) {
                node tmp2(tmp.i, tmp.j + 1, tmp.x, nums2[tmp.j + 1]);
                pq.push(tmp2);
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums1{1, 7, 11}, nums2{2, 4, 6};
    vector<vector<int>> res = so.kSmallestPairs(nums1, nums2, 4);
}