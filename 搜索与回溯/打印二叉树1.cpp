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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};
vector<int> levelOrder(TreeNode *root);
vector<int> levelOrder(TreeNode *root)
{
    vector<int> v;
    if (root == nullptr)
        return v;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *tmp;
    while (!q.empty()) {
        tmp = q.front();
        v.push_back(tmp->val);
        if (tmp->left != nullptr)
            q.push(tmp->left);
        if (tmp->right != nullptr)
            q.push(tmp->right);
        q.pop();
    }
    return v;
}
int main()
{
    TreeNode *t1 = new TreeNode(1, nullptr, nullptr);
    TreeNode *t2 = new TreeNode(2, nullptr, nullptr);
    TreeNode *t3 = new TreeNode(3, nullptr, nullptr);
    TreeNode *t4 = new TreeNode(4, t1, t2);
    TreeNode *t5 = new TreeNode(5, t3, nullptr);
    TreeNode *t6 = new TreeNode(6, nullptr, nullptr);
    TreeNode *t7 = new TreeNode(7, nullptr, nullptr);
    TreeNode *t8 = new TreeNode(8, t4, t5);
    TreeNode *t9 = new TreeNode(9, t6, t7);
    TreeNode *root = new TreeNode(10, t8, t9);
    vector<int> v = levelOrder(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}