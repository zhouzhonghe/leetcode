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
给定一个整数数组 asteroids，表示在同一行的小行星。
对于数组中的每一个元素，其绝对值表示小行星的大小，
正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。
如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
*/
class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); i++) {
            while (!s.empty() && s.top() > 0 && s.top() < -asteroids[i]) {
                s.pop();
            }
            if (!s.empty() && s.top() > 0) {
                if (s.top() == -asteroids[i]) {
                    s.pop();
                    continue;
                } else if (asteroids[i] < 0) {
                    continue;
                }
            }
            s.push(asteroids[i]);
        }
        vector<int> res(s.size());
        for (int i = 0; i < res.size(); i++) {
            res[res.size() - i - 1] = s.top();
            s.pop();
        }
        return res;
    }
};