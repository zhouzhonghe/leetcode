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

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*剑指 Offer II 052
给你一棵二叉搜索树，请 按中序遍历
将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，
并且每个节点没有左子节点，只有一个右子节点。
*/
class Solution {
  public:
    TreeNode *increasingBST(TreeNode *root) {
        stack<TreeNode *> s;
        if (root != nullptr) {
            s.push(root);
            while (root->left != nullptr) {
                s.push(root->left);
                root = root->left;
            }
        }
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            TreeNode *t = cur->right;
            while (t != nullptr) {
                s.push(t);
                t = t->left;
            }
            if (!s.empty()) {
                TreeNode *next = s.top();
                cur->right = next;
                next->left = nullptr;
            }
        }
        return root;
    }
};