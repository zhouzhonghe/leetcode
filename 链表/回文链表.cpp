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
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
给定一个链表的 头节点 head ，请判断其是否为回文链表。
如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
*/
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow->next;
        ListNode *tmp, *pre = nullptr;
        while (middle != nullptr) {
            tmp = middle->next;
            middle->next = pre;
            pre = middle;
            middle = tmp;
        }
        while (pre != nullptr) {
            if (head->val != pre->val) {
                return false;
            } else {
                head = head->next;
                pre = pre->next;
            }
        }
        return true;
    }
};