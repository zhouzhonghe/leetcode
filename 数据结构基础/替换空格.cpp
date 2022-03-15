#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

string replaceSpace(string s);

string replaceSpace(string s)
{
    //双指针
    int len = s.size();
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ')
            num++;
    }
    s.resize(len + 2 * num);
    for (int i = len - 1, j = s.size() - 1; i >= 0; i--, j--) {
        if (s[i] != ' ') {
            s[j] = s[i];
        } else {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
    }
    return s;
}

int main()
{
    string s = "We are happy  .";
    string a = replaceSpace(s);
    cout << a;
}