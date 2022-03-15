#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vote(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> vote[i];
    }
    vector<int> total(n + 1, 1);
    for (int i = n; i >= 0; --i) {
        total[vote[i]] += total[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << total[i] << "\n";
    }
    return 0;
}