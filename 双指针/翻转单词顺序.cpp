#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    string res;
    int i = s.size() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ')
            i--;
        int j = i - 1;
        while (j >= 0 && s[j] != ' ')
            j--;
        if (i >= 0 && j >= -1) {
            res += s.substr(j + 1, i - j) + ' ';
            cout << res << endl;
            i = j;
        }
    }
    if (res.size() >= 1)
        res.erase(res.size() - 1, 1);
    return res;
}

int main()
{
    string s = "1  w fef efa fe   fafef f";
    s = reverseWords(s);
    cout << s << endl;
}