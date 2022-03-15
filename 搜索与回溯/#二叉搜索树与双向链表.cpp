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
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Node
{
  public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
    }

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
//要求不能创建任何新的节点，只能调整树中节点指针的指向。
Node *treeToDoublyList(Node *root)
{
    stack<Node *> s;
    Node *n = root;
    while (root) {
        s.push(root);
        root = root->left;
    }
    Node *pre, *cur, *head;
    if (!s.empty())
        head = s.top();
    cout << head->val << endl;
    while (!s.empty()) {
        pre = s.top();
        s.pop();
        Node *tmp = pre->right;
        while (tmp) {
            s.push(tmp);
            tmp = tmp->left;
        }
        if (!s.empty()) {
            cur = s.top();
            pre->right = cur;
            cur->left = pre;
        } else {
            pre->right = head;
            head->left = pre;
        }
    }
    return head;
}

class Solution
{
  public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

  private:
    Node *pre, *head;   //设定全局变量简化操作
    void dfs(Node *cur) //中序遍历
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

int main()
{
}