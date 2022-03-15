#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int translateNum(int num);

int translateNum(int num)
{
    int a = 1, b = 1, x1 = num % 10, x2 = num % 10;
    int tmp;
    while (num > 9) {
        num /= 10;
        x1 = num % 10;
        tmp = ((x1 * 10 + x2) <= 25 && (x1 * 10 + x2) >= 10) ? a + b : a;
        b = a;
        a = tmp;
        x2 = x1;
    }
    return a;
}
int main()
{
    int num = 12258;
    int x = translateNum(num);
    cout << x;
}