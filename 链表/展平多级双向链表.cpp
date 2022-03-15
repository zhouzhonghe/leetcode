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
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
  public:
    Node *flatten(Node *head) {
        Node *res = head;
        stack<Node *> s;
        s.push(head);
        while (!s.empty()) {
            Node *tmp = s.top();
            s.pop();
            if (tmp != nullptr) {
                if (tmp != head) {
                    head->next = tmp;
                    tmp->prev = head;
                    head = tmp;
                }
                while (head->next != nullptr || head->child != nullptr) {
                    if (head->child != nullptr) {
                        s.push(head->next);
                        head->next = head->child;
                        head->child->prev = head;
                        head->child = nullptr;
                    }
                    head = head->next;
                }
            }
        }
        return res;
    }
};