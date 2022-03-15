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

//给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next
//指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。
class Solution {
  public:
    //快慢指针
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }

    ListNode *detectCycle2(ListNode *head) {
        unordered_map<ListNode *, bool> map;
        while (head != nullptr) {
            if (map.count(head)) {
                return head;
            } else {
                map[head] = true;
            }
            head = head->next;
        }
        return nullptr;
    }
};