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

/*剑指 Offer II 051
路径
被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。
*/
class Solution {
  private:
    int res = INT_MIN;

  public:
    int recur(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = recur(root->left);
        int right = recur(root->right);
        int myMax = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
        res = max(res, myMax);
        int tmp = max(left, right);
        if (tmp > 0) {
            return root->val + tmp;
        } else {
            return root->val;
        }
    }
    int maxPathSum(TreeNode *root) {
        recur(root);
        return res;
    }
};