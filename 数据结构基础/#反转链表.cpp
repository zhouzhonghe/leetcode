#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

ListNode *reverseList(ListNode *head);
ListNode *reverseList2(ListNode *head);

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *tmp;
    while (head != nullptr) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

ListNode *recur(ListNode *cur, ListNode *pre)
{
    if (cur == nullptr)
        return pre;
    ListNode *res = recur(cur->next, cur);
    cur->next = pre;
    return res;
}

ListNode *reverseList2(ListNode *head)
{
    return recur(head, nullptr);
}

int main()
{
    ListNode *n5 = new ListNode(5, nullptr);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);
    ListNode *l = reverseList2(n1);
    while (l != nullptr) {
        cout << l->val;
        l = l->next;
    }
}