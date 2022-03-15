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

class Solution
{
  public:
    int divide(int a, int b)
    {
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        int sign = (a > 0) ^ (b > 0) ? -1 : 1;
        if (a > 0) {
            a = -a;
        }
        if (b > 0) {
            b = -b;
        }
        int res = 0;
        while (a <= b) {
            int value = b;
            int k = 1;
            while (value >= 0xc0000000 && a <= value + value) {
                value += value;
                k += k;
            }
            res -= k;
            a -= value;
        }
        return sign * (-1) * res;
    }
};

int main()
{
    Solution so;
    cout << (-3 >> 2) << endl;
    int res = so.divide(-9, 2);
    cout << res << endl;
}