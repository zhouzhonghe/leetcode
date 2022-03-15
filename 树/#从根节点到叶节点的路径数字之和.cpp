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

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*剑指 Offer II 049
给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：
例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
 */
class Solution { //递归思路
  public:
    int recur(TreeNode *root, int preNum) {
        if (root == nullptr) {
            return 0;
        }
        int num = 10 * preNum + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return num;
        }
        return recur(root->left, num) + recur(root->right, num);
    }
    int sumNumbers(TreeNode *root) {
        return recur(root, 0);
    }
};