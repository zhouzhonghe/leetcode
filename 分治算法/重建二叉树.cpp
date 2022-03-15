#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size() - 1);
    }
    TreeNode *recur(int root, int left, int right)
    {
        if (left > right)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[root]);
        int i = m[preorder[root]];
        node->left = recur(root + 1, left, i - 1);
        node->right = recur(root + 1 + i - left, i + 1, right);
        return node;
    }

  private:
    vector<int> preorder;
    map<int, int> m;
};