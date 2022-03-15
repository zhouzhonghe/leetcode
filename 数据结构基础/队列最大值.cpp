#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class MaxQueue
{
  public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return d.empty() ? -1 : d.front();
    }

    void push_back(int value)
    {
        q.push(value);
        while (!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        if (val == d.front())
            d.pop_front();
        q.pop();
        return val;
    }

  private:
    queue<int> q;
    deque<int> d;
};