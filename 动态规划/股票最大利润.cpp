#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices);

int maxProfit(vector<int> &prices)
{
    int mina = INT_MAX, gain = 0;
    for (int i = 0; i < prices.size(); i++) {
        mina = min(mina, prices[i]);
        gain = min(gain, prices[i] - mina);
    }
    return gain;
}