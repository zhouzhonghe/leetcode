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
给定一棵二叉搜索树和其中的一个节点 p ，找到该节点在树中的中序后继。如果节点没有中序后继，
请返回 null。节点 p 的后继是值比 p.val 大的节点中键值最小的节点，
即按中序遍历的顺序节点 p 的下一个节点。
*/
class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *pre = nullptr;
        while (root != p) {
            if (root->val < p->val) {
                root = root->right;
            } else {
                pre = root;
                root = root->left;
            }
        }
        TreeNode *next = root->right;
        while (next != nullptr && next->left != nullptr) {
            next = next->left;
        }
        return next == nullptr ? pre : next;
    }
};