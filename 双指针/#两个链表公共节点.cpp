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

//输入两个链表，找出它们的第一个公共节点。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *A = headA, *B = headB;
    while (A != B) {
        A = A == nullptr ? headB : A->next;
        B = B == nullptr ? headA : B->next;
    }
    return A;
}