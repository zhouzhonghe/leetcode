#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int numWays(int n);

int numWays(int n)
{
    if (n == 0)
        return 1;
    int x0 = 1, x1 = 1, tmp;
    for (int i = 2; i <= n; i++) {
        tmp = x1;
        x1 = (x0 + x1) % 1000000007;
        x0 = tmp;
    }
    return x1;
}
int main()
{
    int n = 7;
    int x = numWays(n);
    cout << x;
}