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

bool isSubStructure(TreeNode *A, TreeNode *B);
bool recur(TreeNode *A, TreeNode *B);

bool isSubStructure(TreeNode *A, TreeNode *B)
{
    if (A == nullptr || B == nullptr)
        return false;
    if (A->val == B->val) {
        bool res = recur(A, B);
        if (res)
            return true;
    }
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool recur(TreeNode *A, TreeNode *B)
{
    if (B == nullptr)
        return true;
    if (A == nullptr || A->val != B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}