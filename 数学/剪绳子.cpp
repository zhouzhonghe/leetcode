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

int cuttingRope(int n)
{
    if (n == 2)
        return 1;
    else if (n == 3)
        return 2;
    int num3 = 0;
    while (n >= 3) {
        n -= 3;
        num3++;
    }
    if (n == 0)
        return pow(3, num3);
    else if (n == 1)
        return pow(3, num3 - 1) * 4;
    else if (n == 2)
        return pow(3, num3) * 2;

    return 0;
}