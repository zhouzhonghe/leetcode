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

// n & 1表示n除以2的余数
int hammingWeight(uint32_t n)
{
    int res = 0;
    while (n > 0) {
        if ((n & 1) == 1)
            res++;
        n >>= 1;
    }
    return res;
}

int main()
{
    uint32_t n = 7;
    int res = hammingWeight(n);
    cout << res << endl;
}