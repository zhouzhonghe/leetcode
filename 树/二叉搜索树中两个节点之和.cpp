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

/*
给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否
存在两个节点它们的值之和等于k 。假设二叉搜索树中节点的值均唯一。
*/
class Solution {
  private:
    vector<int> nums;

  public:
    void recur(TreeNode *root) {
        if (root != nullptr) {
            recur(root->left);
            nums.push_back(root->val);
            recur(root->right);
        }
    }
    bool findTarget(TreeNode *root, int k) {
        recur(root);
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                return true;
            } else if (nums[i] + nums[j] > k) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};