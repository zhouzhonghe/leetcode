#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int A, B, a, b;
    cin >> A >> B >> a >> b;

    int m = a, n = b;
    while (m % n != 0) {
        int rest = m % n;
        m = n;
        n = rest;
    }
    a /= n;
    b /= n;

    int x = min(A / a, B / b);
    cout << a * x << " " << b * x << "\n";
    return 0;
}