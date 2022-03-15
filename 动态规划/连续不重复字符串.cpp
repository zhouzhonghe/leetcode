#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s);

int lengthOfLongestSubstring(string s)
{
    map<char, int> cmap;
    int len = 0, m = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cmap.find(s[i]) == cmap.end() || cmap[s[i]] < i - len)
            len++;
        else
            len = i - cmap[s[i]];
        if (len > m)
            m = len;
        cmap[s[i]] = i;
    }
    return m;
}

int main()
{
    string s = "pwwkew";
    int n = lengthOfLongestSubstring(s);
    cout << n;
}