#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, a, b, c, d;
    cin >> N >> a >> b >> c >> d;
    long long sum = 1;
    long long n = N * N;
    vector<int> v{a, b, c, d};
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; ++i) {
        long long tmp = 1;
        for (int j = 0; j < v[i]; j++) {
            tmp *= n;
            --n;
        }
        for (int j = 0; j < v[i]; j++) {
            tmp /= j + 1;
        }
        sum = sum * tmp % 998244353;
    }

    cout << sum << endl;
}