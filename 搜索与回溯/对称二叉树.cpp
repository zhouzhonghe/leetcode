#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

bool isSymmetric(TreeNode *root);
bool recur(TreeNode *L, TreeNode *R);

bool recur(TreeNode *L, TreeNode *R)
{
    if (L == nullptr && R == nullptr)
        return true;
    if (L == nullptr || R == nullptr)
        return false;
    if (L->val != R->val)
        return false;
    return recur(L->left, R->right) && recur(L->right, R->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return recur(root->left, root->right);
}