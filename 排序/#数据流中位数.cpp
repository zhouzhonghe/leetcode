#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class MedianFinder
{
  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (S.size() == L.size()) {
            S.push(num);
            L.push(S.top());
            S.pop();
        } else {
            L.push(num);
            S.push(L.top());
            L.pop();
        }
    }

    double findMedian()
    {
        if (S.size() == L.size())
            return (S.top() + L.top()) / 2.0;
        else
            return L.top();
    }

  private:
    priority_queue<int, vector<int>, less<int>> S;
    priority_queue<int, vector<int>, greater<int>> L;
};