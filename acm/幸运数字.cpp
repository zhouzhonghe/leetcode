#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n = 132;
    if (n % 11 == 0) {
        cout << "yes" << endl;
        return 0;
    }
    vector<int> v;
    while (n > 0) {
        v.emplace_back(n % 10);
        n /= 10;
    }
    int nums = 0;
    for (int x : v) {
        if (x == 1) {
            nums++;
        }
    }
    if (nums >= 2) {
        cout << "yes" << endl;
        return 0;
    }
    cout << "no" << endl;
    return 0;
}