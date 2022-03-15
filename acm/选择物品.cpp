#include <iostream>
#include <vector>
using namespace std;

void recur(vector<int> &item, int i, int m, vector<int> tmp) {
    if (tmp.size() == m) {
        for (int j = 0; j < m; j++) {
            cout << tmp[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = i; j < item.size(); j++) {
        tmp.emplace_back(item[j]);
        recur(item, j + 1, m, tmp);
        tmp.erase(tmp.end() - 1);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> item(n);
    for (int i = 0; i < n; i++) {
        item[i] = i + 1;
    }
    recur(item, 0, m, {});
}