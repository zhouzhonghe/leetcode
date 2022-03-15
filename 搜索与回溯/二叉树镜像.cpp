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
    TreeNode(TreeNode *obj) : val(obj->val), left(obj->left), right(obj->right)
    {
    }
};

TreeNode *mirrorTree(TreeNode *root);
void frontOrder(TreeNode *T);

TreeNode *mirrorTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    mirrorTree(root->left);
    mirrorTree(root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}
void frontOrder(TreeNode *T)
{
    TreeNode *temp = T;
    stack<TreeNode *> s;
    while (temp != nullptr || !s.empty()) {
        while (temp != nullptr) {
            s.push(temp);
            int val = temp->val;
            cout << val << endl;
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        temp = temp->right;
    }
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
    TreeNode *t11 = new TreeNode(1, nullptr, nullptr);
    TreeNode *t21 = new TreeNode(2, nullptr, nullptr);
    TreeNode *t31 = new TreeNode(3, nullptr, nullptr);
    TreeNode *t41 = new TreeNode(4, t11, t21);
    TreeNode *t51 = new TreeNode(5, t3, nullptr);
    TreeNode *t61 = new TreeNode(6, nullptr, nullptr);
    TreeNode *t71 = new TreeNode(7, nullptr, nullptr);
    TreeNode *t81 = new TreeNode(8, t41, t51);
    TreeNode *t91 = new TreeNode(9, t61, t71);
    TreeNode *root2 = new TreeNode(10, t81, t91);
    TreeNode *mirror = mirrorTree(root2);
    frontOrder(root);
    frontOrder(mirror);
}