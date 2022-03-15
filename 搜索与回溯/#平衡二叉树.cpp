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
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
//如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
int recur(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = recur(root->left);
    if (left == -1) //剪枝
        return -1;
    int right = recur(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1) //剪枝
        return -1;
    else
        return 1 + max(left, right);
}

bool isBalanced(TreeNode *root)
{
    return (recur(root) != -1);
}