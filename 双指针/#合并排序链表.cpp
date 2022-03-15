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

//链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode(0, nullptr);
    ListNode *head = res;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            res->next = l1;
            l1 = l1->next;
        } else {
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }
    res->next = l1 == nullptr ? l2 : l1;
    return head->next;
}