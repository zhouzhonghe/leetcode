#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool verifyPostorder(vector<int> &postorder);
int findLeft(vector<int> v, int left, int right);
bool recur(vector<int> v, int left, int right);

vector<int> idx;

bool verifyPostorder(vector<int> &postorder)
{
    int root = postorder.size() - 1;
    for (int i = 0; i < postorder.size(); i++) {
        idx.push_back(0);
    }
    return recur(postorder, 0, postorder.size() - 1);
}

bool recur(vector<int> v, int left, int right)
{
    if (left >= right)
        return true;
    int f = findLeft(v, left, right);
    cout << left << ' ' << right << ' ' << f << endl;
    for (int i = left; i <= f; i++) {
        if (v[i] >= v[right])
            return false;
    }
    if (f < 0)
        f = left;
    for (int i = f + 1; i < right; i++) {
        if (v[i] <= v[right])
            return false;
    }
    return recur(v, left, f) && recur(v, f + 1, right - 1);
}

int findLeft(vector<int> v, int left, int right)
{
    for (int i = right - 1; i >= left; i--) {
        if (v[i] < v[right]) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {2, 3, 5, 4, 8, 7, 6};
    bool res = verifyPostorder(v);
    cout << res;
}