#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
请实现一个 MyCalendar
类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。
MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end
时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，
  start <= x <end。
当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。
每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，
返回true。否则，返回 false 并且不要将该日程安排添加到日历中。
请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar();
MyCalendar.book(start, end)
*/
class MyCalendar {
  private:
    struct schedule {
        int l;
        int r;
        schedule(int l, int r) : l(l), r(r) {}
    };
    vector<schedule> v;

  public:
    MyCalendar() {
        schedule first(-1, 0);
        v.push_back(first);
    }

    bool book(int start, int end) {
        auto it = v.begin();
        for (it = v.begin(); it != v.end() - 1; it++) {
            if (start >= it->r && end <= (it + 1)->l) {
                break;
            }
        }
        if (it == v.end() - 1 && start < it->r) {
            return false;
        }
        schedule tmp(start, end);
        v.insert(it + 1, tmp);
        return true;
    }
};