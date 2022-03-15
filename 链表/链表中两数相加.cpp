#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//给定两个 非空链表 l1和
// l2 来代表两个非负整数。数字最高位位于链表开始位置。
//它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//可以假设除了数字 0 之外，这两个数字都不会以零开头。
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *tmp, *l1Rever = nullptr, *l2Rever = nullptr;
        int l1Len = 0, l2Len = 0;
        while (l1 != nullptr) {
            tmp = l1->next;
            l1->next = l1Rever;
            l1Rever = l1;
            l1 = tmp;
            l1Len++;
        }
        while (l2 != nullptr) {
            tmp = l2->next;
            l2->next = l2Rever;
            l2Rever = l2;
            l2 = tmp;
            l2Len++;
        }
        ListNode *A, *B;
        if (l1Len >= l2Len) {
            A = l1Rever;
            B = l2Rever;
        } else {
            A = l2Rever;
            B = l1Rever;
        }
        int flag = 0;
        ListNode *res = A;
        tmp = A;
        while (B != nullptr) {
            A->val += B->val + flag;
            if (A->val >= 10) {
                flag = 1;
                A->val -= 10;
            } else {
                flag = 0;
            }
            if (A->next != nullptr) {
                tmp = tmp->next;
            }
            A = A->next;
            B = B->next;
        }
        while (A != nullptr) {
            A += flag;
            if (A->val >= 10) {
                flag = 1;
                A->val -= 10;
            } else {
                flag = 0;
            }
            if (A->next != nullptr) {
                tmp = tmp->next;
            }
            A = A->next;
        }
        if (flag == 1) {
            ListNode *last = new ListNode(1, nullptr);
            tmp->next = last;
        }
        ListNode *pre = nullptr;
        while (res != nullptr) {
            tmp = res->next;
            res->next = pre;
            pre = res;
            res = tmp;
        }
        return pre;
    }
};