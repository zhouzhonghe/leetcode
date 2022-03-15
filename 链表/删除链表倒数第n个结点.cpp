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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            head = pre->next;
        } else {
            while (cur->next != nullptr) {
                pre = pre->next;
                cur = cur->next;
            }
            pre->next = pre->next->next;
        }
        return head;
    }
};