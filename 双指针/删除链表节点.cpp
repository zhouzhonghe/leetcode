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

ListNode *deleteNode(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    if (head->val == val)
        return head->next;
    ListNode *p1 = head, *p2 = head->next;
    while (p2 != nullptr) {
        if (p2->val == val) {
            p1->next = p2->next;
            break;
        }
        p1 = p2;
        p2 = p2->next;
    }
    return head;
}