#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

vector<int> reversePrint(ListNode *head);
void recur(ListNode *head, vector<int> *v);

void recur(ListNode *head, vector<int> &v)
{
    if (head == nullptr)
        return;
    recur(head->next, v);
    v.push_back(head->val);
}
vector<int> reversePrint(ListNode *head)
{
    vector<int> v;
    recur(head, v);
    return v;
}

int main()
{
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    vector<int> v = reversePrint(n1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}