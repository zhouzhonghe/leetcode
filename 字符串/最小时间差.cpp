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
给定一个 24 小时制（小时:分钟"HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
*/
class Solution {
  public:
    int findMinDifference(vector<string> &timePoints) {
        vector<int> time(timePoints.size());
        for (int i = 0; i < time.size(); i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute = stoi(timePoints[i].substr(3, 2));
            time[i] = hour * 60 + minute;
        }
        sort(time.begin(), time.end());
        int res = INT_MAX;
        for (int i = 1; i < time.size(); i++) {
            res = min(res, time[i] - time[i - 1]);
        }
        res = min(res, time[0] + 1440 - time[time.size() - 1]);
        return res;
    }
};
