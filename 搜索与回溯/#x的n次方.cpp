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

int function(int x, int n)
{
    if (n == 0) {
        return 1;
    }
    int res = function(x, n / 2);
    if (n % 2 == 1) {
        return res * res * x;
    } else {
        return res * res;
    }
}