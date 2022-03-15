#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
  public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int idx = 0;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> s;
        s.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *tmp = s.top();
            if (tmp->val != inorder[idx]) {
                tmp->left = new TreeNode(preorder[i]);
                s.push(tmp->left);
            } else {
                while (!s.empty() && s.top()->val == inorder[idx]) {
                    tmp = s.top();
                    s.pop();
                    idx++;
                }
                tmp->right = new TreeNode(preorder[i]);
                s.push(tmp->right);
            }
        }
        return root;
    }
};
