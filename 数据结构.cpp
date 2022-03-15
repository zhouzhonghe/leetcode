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

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    //数组
    int a[] = {0, 2, 3, 4, 5};
    int n = 5;
    vector<int> b(n + 1); //可变数组
    vector<int> nums{2, 4, 3, 1, 7, 0, 8, 6};
    vector<vector<bool>> visited(10, vector<bool>(5, 0)); // 10*5
    b.push_back(2);                                       //尾部添加

    //链表操作
    ListNode *n1 = new ListNode(2, nullptr);
    ListNode *n2 = new ListNode(3, n1);
    n1->next = n2;

    //栈
    stack<int> stk;
    stk.push(2);
    stk.pop();

    //队列
    queue<int> q1;
    q1.push(2);
    q1.pop();

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
}
