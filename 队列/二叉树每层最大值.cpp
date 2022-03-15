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

//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        int levelMax = INT_MIN;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                levelMax = max(levelMax, tmp->val);
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
            }
            res.push_back(levelMax);
            levelMax = INT_MIN;
        }
        return res;
    }
};