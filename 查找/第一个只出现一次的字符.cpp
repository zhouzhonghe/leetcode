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

char firstUniqChar(string s) {
    unordered_map<char, int> map;
    for (auto x : s) {
        if (map.find(x) == map.end())
            map[x] = 1;
        else
            map[x] += 1;
    }
    for (auto x : s)
        if (map[x] == 1)
            return x;
    return ' ';
}