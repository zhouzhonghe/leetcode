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
/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有 6 个节点，从头节点开始，它们的值依次是
1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
*/
ListNode *getKthFromEnd(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    ListNode *p1 = head, *p2 = head;
    for (int i = 0; i < k - 1; i++)
        p2 = p2->next;
    while (p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}