#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

string reverseLeftWords(string s, int n);

string reverseLeftWords(string s, int n)
{
    int len = s.size();
    string s2 = s;
    for (int i = 0; i < len; i++) {
        if (i < n) {
            s2[i + len - n] = s[i];
        } else {
            s2[i - n] = s[i];
        }
    }
    return s2;
}

int main()
{
    string s = "abcdefg";
    string s2 = reverseLeftWords(s, 3);
    cout << s2;
}