#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class CQueue
{
  public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s2.empty()) {
            if (s1.empty())
                return -1;
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

  private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    CQueue *c = new CQueue();
    c->appendTail(5);
    c->appendTail(2);
    int x1 = c->deleteHead();
    int x2 = c->deleteHead();
    int x3 = c->deleteHead();
    cout << x1 << x2 << x3;
}