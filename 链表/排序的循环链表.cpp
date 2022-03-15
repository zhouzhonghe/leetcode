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

class Node {
  public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

class Solution {
  public:
    Node *insert(Node *head, int insertVal) {
        if (head == nullptr) {
            Node *n = new Node(insertVal);
            n->next = n;
            return n;
        }
        Node *tmp = head->next;
        while (tmp != head) {
            if ((tmp->next->val > insertVal && insertVal >= tmp->val) ||
                (insertVal >= tmp->val && tmp->val > tmp->next->val) ||
                (insertVal <= tmp->next->val && tmp->val > tmp->next->val)) {
                Node *n = new Node(insertVal, tmp->next);
                tmp->next = n;
                return head;
            }
            tmp = tmp->next;
        }
        Node *n = new Node(insertVal, tmp->next);
        tmp->next = n;
        return head;
    }
};