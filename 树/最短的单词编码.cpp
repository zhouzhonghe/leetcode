#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int minimumLengthEncoding(vector<string> &words) {
        set<string> good(words.begin(), words.end());
        for (const string &word : words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string &word : good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};