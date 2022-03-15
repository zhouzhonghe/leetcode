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
/*
完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有
2n-1 个节点）的，并且所有的节点都尽可能地集中在左侧。
设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：
CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v
。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值； CBTInserter.get_root()
将返回树的根节点。
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class CBTInserter {
  public:
    CBTInserter(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            Nodes.push_back(tmp);
            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
        }
    }

    int insert(int v) {
        TreeNode *Node = new TreeNode(v);
        Nodes.push_back(Node);
        int idx = Nodes.size() - 1;
        if ((idx - 1) % 2 == 0) {
            Nodes[(idx - 1) / 2]->left = Node;
        } else {
            Nodes[(idx - 1) / 2]->right = Node;
        }
        return Nodes[(idx - 1) / 2]->val;
    }

    TreeNode *get_root() {
        return Nodes[0];
    }

  private:
    vector<TreeNode *> Nodes;
};