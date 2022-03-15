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

class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;
    unordered_map<Node *, Node *> map;
    map[nullptr] = nullptr;
    Node *copy = new Node(head->val);
    map[head] = copy;
    Node *cur = copy;
    while (cur) {
        if (head->next && map.find(head->next) == map.end()) {
            Node *tmp = new Node(head->next->val);
            cur->next = tmp;
            map[head->next] = tmp;
        } else
            cur->next = map[head->next];
        if (head->random && map.find(head->random) == map.end()) {
            Node *tmp = new Node(head->random->val);
            cur->random = tmp;
            map[head->random] = tmp;
        } else
            cur->random = map[head->random];
        cur = cur->next;
        head = head->next;
    }
    return copy;
}

int main()
{
    unordered_map<Node *, Node *> map;
    Node *head = new Node(3);
    cout << head->random << endl;
    head->next = nullptr;
    head->random = nullptr;
    cout << map[head->next] << endl;
}