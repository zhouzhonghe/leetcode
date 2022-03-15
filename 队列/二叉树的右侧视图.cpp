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

//给定一个二叉树的根节点root，想象自己站在它的右侧，
//按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (i == len - 1) {
                    res.push_back(tmp->val);
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