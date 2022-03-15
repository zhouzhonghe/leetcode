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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        int res;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (i == 0) {
                    res = tmp->val;
                }
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
            }
        }
        return res;
    }
};