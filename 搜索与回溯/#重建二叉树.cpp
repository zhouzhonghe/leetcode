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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> s;
    s.push(root);
    int idx = 0;
    for (int i = 1; i < preorder.size(); i++) {
        TreeNode *tmp = s.top();
        if (tmp->val != inorder[idx]) {
            tmp->left = new TreeNode(preorder[i]);
            s.push(tmp->left);
        } else {
            while (!s.empty() && s.top()->val == inorder[idx]) {
                tmp = s.top();
                s.pop();
                idx++;
            }
            tmp->right = new TreeNode(preorder[i]);
            s.push(tmp->right);
        }
    }
    return root;
}