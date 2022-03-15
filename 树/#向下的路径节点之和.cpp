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

/*剑指 Offer II 050
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径
的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/
class Solution { //前缀和！
  private:
    unordered_map<int, int> sums;

  public:
    int recur(TreeNode *root, int targetSum, int last) {
        if (root == nullptr) {
            return 0;
        }
        last += root->val;
        int res = 0;
        if (sums.count(last - targetSum)) {
            res += sums[last - targetSum];
        }
        sums[last]++;
        res += recur(root->left, targetSum, last) + recur(root->right, targetSum, last);
        sums[last]--;
        return res;
    }
    int pathSum(TreeNode *root, int targetSum) {
        sums[0] = 1;
        return recur(root, targetSum, 0);
    }
};