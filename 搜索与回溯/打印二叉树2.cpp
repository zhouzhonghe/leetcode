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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    while (!q.empty()) {
        vector<int> tmp;
        int len = q.size();
        for (int i = 0; i < len; i++) { //通过指定循环次数来确定每层节点数
            TreeNode *t = q.front();
            tmp.push_back(t->val);
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        res.push_back(tmp);
    }
    return res;
}