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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Node
{
  public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
    }

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

void recur(TreeNode *root, int &k, int &res)
{
    if (root == nullptr)
        return;
    recur(root->right, k, res);
    if (k == 0)
        return;
    if (--k == 0) {
        res = root->val;
        return;
    }
    recur(root->left, k, res);
}

int kthLargest(TreeNode *root, int k)
{
    int res;
    recur(root, k, res);
    return res;
}

int main()
{
}