#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> pathSum(TreeNode *root, int target);
void recur(TreeNode *root, int target, vector<int> &v2, vector<vector<int>> &v);

void recur(TreeNode *root, int target, vector<int> &v2, vector<vector<int>> &v) {
    if (root == nullptr)
        return;
    v2.push_back(root->val);
    target -= root->val;
    if (target == 0 && root->left == nullptr && root->right == nullptr)
        v.push_back(v2);
    recur(root->left, target, v2, v);
    recur(root->right, target, v2, v);
    v2.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int target) {
    vector<vector<int>> v;
    vector<int> v2;
    recur(root, target, v2, v);
    return v;
}

int main() {
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
    vector<vector<int>> v = pathSum(root, 26);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}