#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<double> dicesProbability(int n);

vector<double> dicesProbability(int n)
{
    vector<double> a(6, 1 / 6.0);
    for (int i = 2; i <= n; i++) {
        vector<double> b(5 * i + 1, 0);
        for (int j = 0; j < a.size(); j++) {
            for (int k = j; k < j + 6; k++) {
                b[k] += a[j] / 6.0;
            }
        }
        a = b;
    }
    return a;
}
int main()
{
    int n = 2;
    vector<double> v = dicesProbability(n);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}