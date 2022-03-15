#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int nthUglyNumber(int n);

int nthUglyNumber(int n)
{
    int a = 0, b = 0, c = 0;
    int n2, n3, n5;
    vector<int> dp;
    dp.push_back(1);
    for (int i = 1; i < n; i++) {
        n2 = dp[a] * 2;
        n3 = dp[b] * 3;
        n5 = dp[c] * 5;
        dp.push_back(min(min(n2, n3), n5));
        if (dp[i] == n2)
            a++;
        if (dp[i] == n3)
            b++;
        if (dp[i] == n5)
            c++;
    }
    return dp[n - 1];
}