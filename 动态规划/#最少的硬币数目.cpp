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

/*剑指 Offer II 103
给定不同面额的硬币 coins 和一个总金额
amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。你可以认为每种硬币的数量是无限的。
*/
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> v(amount + 1, amount + 1);
        v[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    v[i] = min(v[i], v[i - coin] + 1);
                }
            }
        }
        return v[amount] <= amount ? v[amount] : -1;
    }
};
/*
我们采用自下而上的方式进行思考。仍定义 F(i) 为组成金额 i 所需最少的硬币数量，假设在计算
 F(i) 之前，我们已经计算出 F(0) 至 F(i-1) 的答案。 则 F(i) 对应的转移方程应为
*/