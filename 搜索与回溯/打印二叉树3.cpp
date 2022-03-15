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
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    bool flag = true;
    while (!q.empty()) {
        int len = q.size();
        vector<int> tmp(len);
        for (int i = 0; i < len; i++) {
            TreeNode *t = q.front();
            q.pop();
            if (flag)
                tmp[i] = t->val;
            else
                tmp[len - i - 1] = t->val;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        flag = !flag;
        res.push_back(tmp);
    }
    return res;
}

int main()
{
}