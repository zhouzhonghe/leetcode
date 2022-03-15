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

//给定一个非负整数 n ，请计算 0 到 n
//之间的每个数字的二进制表示中1的个数，并输出一个数组。

class Solution
{
  public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            int x = i;
            int a = 1;
            while (x > 1) {
                if (x % 2 != 0) {
                    a++;
                }
                x = x >> 1;
            }
            res.push_back(a);
        }
        return res;
    }

    //动态规划***
    vector<int> countBits2(int n)
    {
        vector<int> res;
        res.push_back(0);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            res.push_back(res[i - highBit] + 1);
        }
        return res;
    }
    vector<int> countBits3(int n)
    {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            res.push_back(res[i >> 1] + (i & 1));
        }
        return res;
    }
};