#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        stk.push(x);
        if (assist.empty() || x <= assist.top())
            assist.push(x);
    }

    void pop()
    {
        if (stk.top() == assist.top())
            assist.pop();
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int min()
    {
        return assist.top();
    }

  private:
    stack<int> stk;
    stack<int> assist;
};