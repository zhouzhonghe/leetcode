#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

double myPow(double x, int n);

double myPow(double x, int n)
{
    if (n == 0 || x == 1)
        return 1;
    if (x == 0)
        return 0;
    long tmp = n;
    if (tmp < 0) {
        tmp = -tmp;
        x = 1 / x;
    }
    double sum = 1;
    while (tmp > 0) {
        if (tmp % 2 != 0)
            sum *= x;
        x *= x;
        tmp /= 2;
    }
    return sum;
}

int main()
{
    double sum = myPow(2, 10);
    cout << sum << endl;
}