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

//快慢指针找链表中点
class Solution {
  public:
    void reorderList(ListNode *head) {
        stack<ListNode *> s;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->next;
        }
        int len = s.size();
        ListNode *l = head;
        while (s.size() > len / 2) {
            tmp = l->next;
            if (l != s.top()) {
                l->next = s.top();
            } else {
                l->next = nullptr;
                break;
            }
            if (s.top() != tmp) {
                s.top()->next = tmp;
            } else {
                s.top()->next = nullptr;
                break;
            }
            l = tmp;
            s.pop();
        }
    }
};