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
/*
写一个 RecentCounter 类来计算特定时间范围内最近的请求。
请实现 RecentCounter 类：
RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000
毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
保证 每次对 ping的调用都使用比之前更大的 t 值。
*/
class RecentCounter {
  public:
    RecentCounter() {}

    int ping(int t) {
        while (!q.empty() && q.front() + 3000 < t) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }

  private:
    queue<int> q;
};