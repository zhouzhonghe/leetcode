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
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。
实现 MovingAverage 类：
MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数
next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size
个值的移动平均值，即滑动窗口里所有数字的平均值。
*/
class MovingAverage {
  public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }

  private:
    queue<int> q;
    int size;
    double sum;
};