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

int fib(int n)
{
    if (n == 0)
        return 0;
    int x0 = 0, x1 = 1;
    for (int i = 1; i < n; i++) {
        int tmp = (x0 + x1) % 1000000007; //循环取余法
        x0 = x1;
        x1 = tmp;
    }
    return x1;
}

int main()
{
}